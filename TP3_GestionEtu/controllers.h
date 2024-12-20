#pragma once
#include <QStringList>
#include <QMessageBox>
#include "promotion.h"

class Controller
{
public:
    virtual ~Controller() {}
    virtual void control(const QStringList& list) = 0;
};

class ControllerRemoveList : public Controller
{
private:
    Promotion* promo;
public:

    ControllerRemoveList(Promotion* promo) : promo(promo) {}

    virtual void control(const QStringList& list) override
    {
        for (QString student: list)
        {
            promo->remove(student);
        }
    }
};


class ControllerAddForm : public Controller
{
private:
    Promotion* promo;
public:

    ControllerAddForm(Promotion* promo) : promo(promo) {

    }

    virtual void control(const QStringList& list) override
    {
        if (list.size() != 5) return;

        Student studentOld = promo->find(list[0]);
        if (studentOld.getCardID() != "")
        {
            QMessageBox::warning(nullptr,"Add Student","The student already exist.");
            return;
        }

        if (list[0] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "ID can't be null"); return;
        }
        if (list[1] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "firstname can't be null"); return;
        }
        if (list[2] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "lastname can't be null"); return;
        }
        if (list[3] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "bac can't be null"); return;
        }
        if (list[4] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "department can't be null"); return;
        }

        Student studentNew(list[0], list[1], list[2], list[3], list[4]);
        promo->add(studentNew);
    }
};


class ControllerRemoveForm : public Controller
{
private:
    Promotion* promo;
public:
    ControllerRemoveForm(Promotion* promo) : promo(promo) {}

    virtual void control(const QStringList& list) override
    {
        qDebug()<<"Controller";
        if (list.size() != 1) return;
        Student student = promo->find(list[0]);
        if (student.getCardID()!=""){
             qDebug()<<"removedebut";
            promo->remove(student);
              qDebug()<<"removefin";
        }

    }
};
