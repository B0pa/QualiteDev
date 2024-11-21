#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "promotion.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"

#include "iostream"
using namespace std;

class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    TP3_GestionEtu(QWidget *parent = nullptr);
    TP3_GestionEtu(Promotion* promo,  QWidget* parent = nullptr);
    ~TP3_GestionEtu() {delete promo;}
private:
    Ui::TP3_GestionEtuClass ui;

    Promotion* promo;

    ViewList* listView;
    ViewForms* listForm;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;
};
