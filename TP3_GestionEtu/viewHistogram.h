#pragma once
#include "promotion.h"
#include <QWidget>
#include <QBarSeries>
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QValueAxis>

    class ViewHistogram : public QObject, public Observer
{
    Q_OBJECT

private:
    Promotion* promo;
    QWidget* widget;
    QBarSeries* series;
    QValueAxis* axisY;

public:
    ViewHistogram(Promotion*, QWidget*);

    void update() override;
};

