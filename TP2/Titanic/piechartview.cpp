#include "pieChartView.h"

QWidget* PieChartView::getChartView(const Data &dbf) const {
    QVector<int> HF(2,0);

    QPieSeries *series = new QPieSeries();
    for (const auto &d:dbf.getPassengerList()) {
        ++HF[d.getSex()];
    }

    series->append("F",HF[0]);
    series->append("H",HF[1]);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Proportions H/F");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

