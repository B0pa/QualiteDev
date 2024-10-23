#ifndef MULTICHARTVIEW_H
#define MULTICHARTVIEW_H

#include "abstractchartview.h"

class MultiChartView : public AbstractChartView
{
public:
    MultiChartView() :AbstractChartView()  {}
    virtual QWidget* getChartView(const Data& dbf) const override;
};

#endif // MULTICHARTVIEW_H
