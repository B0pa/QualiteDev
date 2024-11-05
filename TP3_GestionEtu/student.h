#pragma once
#include <QDebug>
#include <QString>

/**
 * @brief Student informations
 * @author Fabrice Jaillet
*/
class Student
{
private:
    QString cardID;
    QString firstname;
    QString lastname;
    QString bac;
    QString department;

public: 
    Student(QString =QString(), QString =QString(), QString =QString(), QString =QString(), QString =QString());

    const QString getCardID() const { return cardID; }
    const QString getFirstname() const { return firstname; }
    const QString getLastname() const { return lastname; }
    const QString getBac() const { return bac; }
    const QString getDepartment() const { return department; }

    const QString getText() const { return cardID + " - " + lastname + " " + firstname + " (" + department + ")"; }

    friend QDebug operator<<(QDebug os, const Student& dt);
};

QDebug operator<<(QDebug os, const Student& dt);
