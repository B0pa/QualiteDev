#include "data.h"
#include "iostream"

using namespace std;

QList<Passenger> Data::getPassengerList() const
{
    return passengerList;
}

Data::Data() {}


void Data::readList(const QString &fileName)
{

    QFile file (fileName);
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        in.readLine();
        in.readLine();
        in.readLine();
        in.readLine();
        in.readLine();
        QString id;
        int cl, ag, sx, sv;
        while (!in.atEnd())
        {
            in >> id;
            in >> cl;
            in >> ag;
            in >> sx;
            in >> sv;
            passengerList.append(Passenger(id, cl, ag, sx, sv));
        }
        file.close();
    }
    else{
        qDebug() << "failed to open file in data";
    }
    // cout<<passengerList.size();
}
