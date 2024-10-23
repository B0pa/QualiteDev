#include "passenger.h"

QString Passenger::getIden() const
{
    return iden;
}

int Passenger::getClass_() const
{
    return class_;
}

int Passenger::getAge() const
{
    return age;
}

int Passenger::getSex() const
{
    return sex;
}

int Passenger::getSurvived() const
{
    return survived;
}

Passenger::Passenger() {}

Passenger::Passenger(QString iden, int class_, int age, int sex, int survived) : iden(iden),
    class_(class_),
    age(age),
    sex(sex),
    survived(survived)
{}
