#ifndef DATA_H
#define DATA_H

#include "passenger.h"
#include "QList"
#include "QFile"
#include "QTextStream"
#include "QDebug"

class Data
{
private:
    QList<Passenger> passengerList;
public:
    Data();
    Data(const QString& fileName){
        readList(fileName);
    }
    void readList(const QString &fileName);

    QList<Passenger> getPassengerList() const;
};

#endif // DATA_H
