#ifndef PASSENGER_H
#define PASSENGER_H
#include "QString"

class Passenger
{
private :
    QString iden;
    int class_;
    int age;
    int sex;
    int survived;
public:
    Passenger();
    Passenger(QString iden, int class_, int age, int sex, int survived);
    QString getIden() const;
    int getClass_() const;
    int getAge() const;
    int getSex() const;
    int getSurvived() const;
};

#endif // PASSENGER_H
