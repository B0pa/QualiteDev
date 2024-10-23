#ifndef TITANIC_H
#define TITANIC_H

#include <QApplication>
#include <QMainWindow>
#include <QString>
#include "abstractchartview.h"
#include "piechartview.h"
#include "barchartview.h"
#include "multichartview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Titanic;
}
QT_END_NAMESPACE

class Titanic : public QMainWindow
{
    Q_OBJECT

public:
    explicit Titanic(const QString& filename=QString(),QWidget *parent = nullptr);
    ~Titanic();
    void setChartView(std::unique_ptr<AbstractChartView> &&cv) {
        chartview = std::move(cv); }

    Data getDbf() const;

private slots:

    void showPieChart();
    void showBarChart();
    void showMultiBarChart();

private:
    Ui::Titanic *ui;
    std::unique_ptr<AbstractChartView> chartview;
    Data dbf;
};
#endif // TITANIC_H
