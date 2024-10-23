#include "titanic.h"
#include "ui_titanic.h"
#include "data.h"

Titanic::Titanic(const QString& filename,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Titanic),
    dbf(filename)
{
    ui->setupUi(this);
    connect(ui->actionRatio_H_F, &QAction::triggered, this, &Titanic::showPieChart);
    connect(ui->actionCat_gorie, &QAction::triggered, this, &Titanic::showBarChart);
    connect(ui->action_ge_cat_gorie, &QAction::triggered, this, &Titanic::showMultiBarChart);
    ui->actionRatio_H_F->trigger();
}

Titanic::~Titanic()
{
    delete ui;
}

void Titanic::showPieChart() {

    setChartView(std::make_unique<PieChartView>());
    setCentralWidget( chartview->getChartView(dbf));
}

void Titanic::showBarChart() {

    setChartView(std::make_unique<BarChartView>());
    setCentralWidget( chartview->getChartView(dbf));
}

void Titanic::showMultiBarChart() {

    setChartView(std::make_unique<MultiChartView>());
    setCentralWidget( chartview->getChartView(dbf));
}

Data Titanic::getDbf() const
{
    return dbf;
}
