#pragma once
#include "promotion.h"
#include "ui_TP3_GestionEtu.h"
#include <QGroupBox>
#include "QStringList"
#include "controllers.h"

class ViewForms : public QObject
{
private:
    Ui::TP3_GestionEtuClass* ui;
    Promotion* promo;
public:
    ViewForms(Promotion*, Ui::TP3_GestionEtuClass*);
    void init();
    void update();
public slots:
    void add();
    void remove();
};
