#ifndef ABSTRACTCHARTVIEW_H
#define ABSTRACTCHARTVIEW_H
#include <QWidget>
#include "data.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QHorizontalBarSeries>
#include <QHorizontalStackedBarSeries>
#include <QtCharts/QValueAxis>
#include <QtWidgets/QGridLayout>

class AbstractChartView
{
public:
    AbstractChartView();
    virtual ~AbstractChartView(){};

    virtual QWidget* getChartView(const Data& dbf) const =0;

};

#endif // ABSTRACTCHARTVIEW_H
