#include "TP3_GestionEtu.h"
#include <QDir>

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent), promo(nullptr)
{
    ui.setupUi(this);

    // Create Promotion
    promo = new Promotion( QDir::currentPath()+"/../../../data/promoDUT.csv");

    // Create Views and add connectors

    listView = new ViewList(promo, ui.listWidget);
    connect(ui.pushButton_delete_list, &QPushButton::pressed, listView, &ViewList::remove);

    listForm = new ViewForms(promo, &ui);
    connect(ui.pushButton_addStudent, &QPushButton::pressed, listForm, &ViewForms::add);
    connect(ui.pushButton_delete_number, &QPushButton::pressed, listForm, &ViewForms::remove);

    pieChartView=new ViewPieChart(promo, ui.groupBox_department);
    histogramView = new ViewHistogram(promo, ui.groupBox_bacs);

    // Handle Observers
    promo->addObserver(listView);
    promo->addObserver(pieChartView);
    promo->addObserver(histogramView);
}

