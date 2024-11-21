#include "viewForms.h"


ViewForms::ViewForms(Promotion* promo, Ui::TP3_GestionEtuClass* ui) : ui(ui), promo(promo)
{
    init();
    update();
}

void ViewForms::init()
{
    QStringList listBac;
    listBac << "S" << "ES" << "L" << "STI";
    ui->lineEdit_add_BAC->addItems(listBac);

    QStringList listDep;
    for (int i = 1; i < 96; i++)
    {
        listDep.append( QString::number(i).rightJustified(2, '0'));
    }
    ui->lineEdit_add_department->addItems(listDep);
}

void ViewForms::update()
{
    ui->lineEdit_add_number->clear();
    ui->lineEdit_add_firstname->clear();
    ui->lineEdit_add_lastname->clear();
    ui->lineEdit_add_BAC->setCurrentIndex(-1);
    ui->lineEdit_add_department->setCurrentIndex(-1);
}

void ViewForms::add()
{
    QStringList list;
    list << ui->lineEdit_add_number->text() <<
        ui->lineEdit_add_firstname->text() <<
        ui->lineEdit_add_lastname->text() <<
        ui->lineEdit_add_BAC->itemText(ui->lineEdit_add_BAC->currentIndex()) <<
        ui->lineEdit_add_department->itemText(ui->lineEdit_add_department->currentIndex());
    ControllerAddForm control(promo);
    control.control(list);
    qDebug()<<list;
}

void ViewForms::remove()
{
    QStringList id;
    qDebug()<<id;
    id << ui->lineEdit_remove_number->text() ;
    qDebug()<<id;
    ControllerRemoveForm control(promo);
    control.control(id);
}
