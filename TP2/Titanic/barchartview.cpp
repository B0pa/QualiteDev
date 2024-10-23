#include "barchartview.h"

QWidget* BarChartView::getChartView(const Data &dbf) const {

    QVector<QBarSet*> set(2,nullptr);

    set[0] = new QBarSet("Péri");
    set[1] = new QBarSet("Survécu");

    QVector< QVector<int> > survived(2, QVector<int>(4,0));
    for (auto d:dbf.getPassengerList()) {
        ++survived[d.getSurvived()][d.getClass_()];
    }

    QBarSeries *series = new QBarSeries();
    for (int i=0; i<2; ++i) {
        for (int j=0; j<4; ++j) {
            set[i]->append(survived[i][j]);
        }
        series->append(set[i]);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Survivants/Catégorie");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Équipage" << "Première" << "Deuxième" << "Troisième";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
