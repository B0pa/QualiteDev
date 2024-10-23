#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "abstractchartview.h"

class BarChartView : public AbstractChartView
{
public:
    BarChartView() :AbstractChartView()  {}
    virtual QWidget* getChartView(const Data& dbf) const override;
};

#endif // BARCHARTVIEW_H
