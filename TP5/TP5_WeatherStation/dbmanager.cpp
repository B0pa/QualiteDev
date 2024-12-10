#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>


/**
 * @class DbManager
 * @brief The DbManager class provides a database manager to handle pollution data.
 *
 * @param path Path to the SQLite database.
 */
DbManager::DbManager(const QString &path)
{
    sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName(path);

    if (!sqldb.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
        QSqlQuery query;
        query.exec("DROP TABLE IF EXISTS pollution;");
        query.prepare("CREATE TABLE pollution(id INTEGER PRIMARY KEY, dt INTEGER, aqi INTEGER); ");

        if (!query.exec())
        {
            qDebug() << "Error: Requete creation de table non effectuee...";
        }
        else {
            qDebug() << "Table pollution creer !";
        }
    }
}

/**
 * @brief Destructor for the DbManager class. Closes the database connection if it is open.
 */
DbManager::~DbManager()
{
    if (sqldb.isOpen())
    {
        sqldb.close();
    }
}

/**
 * @brief Checks if the database connection is open.
 *
 * @return True if the database connection is open, false otherwise.
 */
bool DbManager::isOpen() const
{
    return sqldb.isOpen();
}

/**
 * @brief Creates the 'pollution' table in the database.
 *
 * @return True if the table was successfully created, false otherwise.
 */
bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS pollution;");
    query.prepare("CREATE TABLE pollution(id INTEGER PRIMARY KEY, dt INTEGER, aqi INTEGER);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'pollution': one might already exist.";
        success = false;
    }

    return success;
}

/**
 * @brief Adds a data entry to the 'pollution' table.
 *
 * @param dt The datetime of the data entry.
 * @param aqi The Air Quality Index of the data entry.
 * @return True if the data entry was successfully added, false otherwise.
 */
bool DbManager::addData(int dt, int aqi) {

    bool success = false;

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO pollution (dt,aqi) VALUES (:dt,:aqi)");
    queryAdd.bindValue(":dt", dt);
    queryAdd.bindValue(":aqi", aqi);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add dt/aqi failed: " << queryAdd.lastError();
    }

    notifyObserver();
    return success;
}

/**
 * @brief Removes a data entry from the 'pollution' table.
 *
 * @param dt The datetime of the data entry to remove.
 * @return True if the data entry was successfully removed, false otherwise.
 */
bool DbManager::removeData(int dt)
{
    bool success = false;

    if (entryExists(dt))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM pollution WHERE dt = (:dt)");
        queryDelete.bindValue(":dt", dt);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove data failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove data failed: dt doesnt exist";
    }

    return success;
}

/**
 * @brief Retrieves all data from the 'pollution' table.
 *
 * @return A QMap containing all data from the 'pollution' table.
 */
QMap<int,int> DbManager::getAllData()const{
    QMap<int,int> values;
    QSqlQuery query("SELECT * FROM pollution");
    int idDt = query.record().indexOf("dt");
    int idAqi = query.record().indexOf("aqi");
    while(query.next()){
        int dt = query.value(idDt).toInt();
        int aqi = query.value(idAqi).toInt();
        values.insert(dt,aqi);
    }
    return values;
}



/**
 * @brief Prints all data from the 'pollution' table to the console.
 */
void DbManager::printAllData() const
{
    qDebug() << "Data in db:";
    QSqlQuery query("SELECT * FROM pollution");
    int idDt = query.record().indexOf("dt");
    int idAqi = query.record().indexOf("aqi");
    while (query.next())
    {
        int dt = query.value(idDt).toInt();
        int aqi = query.value(idAqi).toInt();
        qDebug() << "===" << dt << " " << aqi;
    }
}

/**
 * @brief Checks if a data entry exists in the 'pollution' table.
 *
 * @param dt The datetime of the data entry to check.
 * @return True if the data entry exists, false otherwise.
 */
bool DbManager::entryExists(int dt) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT dt FROM pollution WHERE dt = (:dt)");
    checkQuery.bindValue(":dt", dt);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "data exists failed: " << checkQuery.lastError();
    }

    return exists;
}

/**
 * @brief Removes all data from the 'pollution' table.
 *
 * @return True if all data was successfully removed, false otherwise.
 */
bool DbManager::removeAllData()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM pollution");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all data failed: " << removeQuery.lastError();
    }

    return success;
}
