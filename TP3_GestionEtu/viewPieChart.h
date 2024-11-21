#pragma once

#include "promotion.h"

#include <QPieSeries>
#include "promotion.h"
#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QChartGlobal>
#include "qchartglobal.h"



/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart : public QObject, public Observer
{

public:
     ViewPieChart(Promotion*, QWidget*);
     void update() override;
private:
    Promotion* promo;
    QWidget* widget;
    QPieSeries* series;
};

