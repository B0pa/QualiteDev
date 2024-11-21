#pragma once
#include <QList>
#include <QDebug>
#include "student.h"
#include "observer.h"
#include "QFile"
#include "QVector"
#include <QMessageBox>

/**
 * @brief Promotion manage the list of students
 * @author Fabrice Jaillet
*/
class Promotion : private Observable
{
private:
    QList<Student> students;
    QVector<Observer*> observers;

public:
    Promotion(QString filename);
    ~Promotion() { qDebug() << "[-] Promotion"; }

    void add(const Student&);
    void remove(const Student&);
    void remove(const QString &);

    Student find(QString) const;

    QStringList getList() const;
    QMap<QString, int> getListDepartment() const;
    QMap<QString, int> getListBacs() const;

    friend QDebug operator<<(QDebug os, const Promotion& dt);
    virtual void addObserver(Observer* observer) override { observers.append(observer); }
    virtual void removeObserver(Observer* observer) override { observers.removeAll(observer); }
    virtual void notifyObserver() const override {for (Observer* observer : observers) observer->update();}
};

QDebug operator<<(QDebug os, const Promotion& dt);

