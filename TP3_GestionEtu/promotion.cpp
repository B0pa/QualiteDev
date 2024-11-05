#include "promotion.h"

/**
 * @brief Constructor of the Promotion Class to manage the List of student
 * @param filename, path to the data CSV file
*/
Promotion::Promotion(QString filename)
{

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QStringList split = in.readLine().split(';');
            add(Student(split[0], split[1], split[2], split[4], split[3]));
        }

        file.close();
    }
    else
    {
        qDebug() << "Echec ouverture fichier : " << filename << "\n";
    }
}


/**
 * @brief Function to add a student to the promotion list
 * @param etu The current student
*/
void Promotion::add(const Student &etu)
{
    students.append(etu);
}

/**
 * @brief Function to remove a specific student
 * @param listText the student text as in the view list
*/
void Promotion::remove(const QString& listText)
{

}

/**
 * @brief Function to remove a specific student
 * @param etu The student to remove
*/
void Promotion::remove(const Student &etu)
{

}

/**
 * @brief Search the student according to his ID Card
 * @param cardID ID card of the student
 * @return Student
*/
Student Promotion::find(QString cardID) const
{
    return Student();
}

/**
 * @brief Print the student information
*/
QDebug operator<<(QDebug  os, const Promotion& dt)
{
    for (const Student& student : dt.students)
    {
        os << student << "\n";
    }

    return os;
}


QStringList Promotion::getList() const
{
    QStringList list;

    for (const Student& student : students)
    {
        list.append(student.getText());
    }

    list.sort();

    return list;
}

QMap<QString, int> Promotion::getListDepartment() const
{
    QMap<QString, int> series;

    for (const Student& student : students)
    {
        QString dept = student.getDepartment();
        if (series.contains(dept)) series.insert(dept, series.value(dept) + 1);
        else series.insert(dept, 1);
    }

    return series;
}

QMap<QString, int> Promotion::getListBacs() const
{
    QMap<QString, int> series;

    series.insert("S", 0);
    series.insert("ES", 0);
    series.insert("L", 0);
    series.insert("STI", 0);
    series.insert("STG", 0);
    series.insert("Etr", 0);
    series.insert("Autre", 0);

    for (const Student& student : students)
    {
        QString bac = student.getBac();
        if (series.contains(bac)) series.insert(bac, series.value(bac) + 1);
        else series.insert(bac, 1);
    }

    return series;
}
