#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include <QWidget>
#include <QVector>
#include <QPieSeries>
#include <QChartView>
#include "data.h"
#include "abstractChartView.h"


class PieChartView : public AbstractChartView
{
public:
    PieChartView() :AbstractChartView() {}
    virtual QWidget* getChartView(const Data& dbf) const override;
};

#endif // PIECHARTVIEW_H
