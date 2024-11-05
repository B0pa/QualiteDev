#include "student.h"

/**
 * @brief Constructor of the Sudent class
*/
Student::Student(QString cardID, QString firstname, QString lastname, QString bac, QString department):
	cardID(cardID), firstname(firstname), lastname(lastname), bac(bac), department(department)
{
}

/**
 * @brief Print the student information
*/
QDebug operator<<(QDebug os, const Student& dt)
{
    os << dt.cardID << " " << dt.firstname << " " << dt.lastname << " " << dt.bac << " " << dt.department;

    return os;
}
