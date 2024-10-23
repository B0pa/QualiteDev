#include "multichartview.h"

QWidget* MultiChartView::getChartView(const Data &dbf) const {

    QChart::AnimationOption animation = QChart::AllAnimations;
    QBarSet* set00= new QBarSet("Population");

    QVector<int> population00(4,0);
    for (auto d:dbf.getPassengerList()) {
        ++population00[d.getClass_()];
    }

    QHorizontalBarSeries *series00 = new QHorizontalBarSeries();
    for (int i=0; i<4; ++i) {
        set00->append(population00[i]);
    }
    series00->append(set00);

    QChart *chart00 = new QChart();
    chart00->addSeries(series00);
    chart00->setTitle("Population/Catégorie");
    chart00->setAnimationOptions(animation);

    QStringList categories00;
    categories00 << "Équipage" << "Première" << "Deuxième" << "Troisième";
    QBarCategoryAxis *axisY00 = new QBarCategoryAxis();
    axisY00->append(categories00);
    chart00->addAxis(axisY00, Qt::AlignLeft);
    series00->attachAxis(axisY00);

    QValueAxis *axisX00 = new QValueAxis();
    axisX00->setLabelFormat("%d");
    chart00->addAxis(axisX00, Qt::AlignBottom);
    series00->attachAxis(axisX00);

    chart00->legend()->setVisible(true);
    chart00->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView00 = new QChartView(chart00);
    chartView00->setRenderHint(QPainter::Antialiasing);

    QVector<QBarSet*> set01(2,nullptr);

    set01[0] = new QBarSet("Péri");
    set01[1] = new QBarSet("Survécu");

    QVector< QVector<int>> survived01(2, QVector<int>(4,0));
    for (auto d:dbf.getPassengerList()) {
        ++survived01[d.getSurvived()][d.getClass_()];
    }

    QHorizontalStackedBarSeries *series01 = new QHorizontalStackedBarSeries();
    for (int i=1; i>=0; --i) {
        for (int j=0; j<4; ++j) {
            set01[i]->append(survived01[i][j]);
        }
        series01->append(set01[i]);
    }

    QChart *chart01 = new QChart();
    chart01->addSeries(series01);
    chart01->setTitle("Survivants/Catégorie");
    chart01->setAnimationOptions(animation);

    QStringList categories01;
    categories01 << "Équipage" << "Première" << "Deuxième" << "Troisième";
    QBarCategoryAxis *axisY01 = new QBarCategoryAxis();
    axisY01->setReverse();
    axisY01->append(categories01);
    chart01->addAxis(axisY01, Qt::AlignLeft);
    series01->attachAxis(axisY01);

    QValueAxis *axisX01 = new QValueAxis();
    axisX01->setLabelFormat("%d");
    chart01->addAxis(axisX01, Qt::AlignBottom);
    series01->attachAxis(axisX01);

    chart01->legend()->setVisible(true);
    chart01->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView01 = new QChartView(chart01);
    chartView01->setRenderHint(QPainter::Antialiasing);

    QBarSet* set10= new QBarSet("Population");

    QVector<int> population10(4,0);
    for (auto d:dbf.getPassengerList()) {
        ++population10[d.getAge()];
    }

    QHorizontalBarSeries *series10 = new QHorizontalBarSeries();
    for (int i=0; i<4; ++i) {
        set10->append(population10[i]);
    }
    series10->append(set10);

    QChart *chart10 = new QChart();
    chart10->addSeries(series10);
    chart10->setTitle("Population/Âge");
    chart10->setAnimationOptions(animation);

    QStringList categories10;
    categories10 << "Enfant" << "Adulte";
    QBarCategoryAxis *axisY10 = new QBarCategoryAxis();
    axisY10->append(categories10);
    chart10->addAxis(axisY10, Qt::AlignLeft);
    series10->attachAxis(axisY10);

    QValueAxis *axisX10 = new QValueAxis();
    axisX10->setLabelFormat("%d");
    chart10->addAxis(axisX10, Qt::AlignBottom);
    series10->attachAxis(axisX10);

    chart10->legend()->setVisible(true);
    chart10->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView10 = new QChartView(chart10);
    chartView10->setRenderHint(QPainter::Antialiasing);

    QVector<QBarSet*> set11(2,nullptr);

    set11[0] = new QBarSet("Péri");
    set11[1] = new QBarSet("Survécu");

    QVector< QVector<int> > survived11(2, QVector<int>(4,0));
    for (auto d:dbf.getPassengerList()) {
        ++survived11[d.getSurvived()][d.getAge()];
    }

    QHorizontalStackedBarSeries *series11 = new QHorizontalStackedBarSeries();
    for (int i=1; i>=0; --i) {
        for (int j=0; j<4; ++j) {
            set11[i]->append(survived11[i][j]);
        }
        series11->append(set11[i]);
    }

    QChart *chart11 = new QChart();
    chart11->addSeries(series11);
    chart11->setTitle("Survivants/Âge");
    chart11->setAnimationOptions(animation);

    QStringList categories11;
    categories11 << "Enfant" << "Adulte";;
    QBarCategoryAxis *axisY11 = new QBarCategoryAxis();
    axisY11->append(categories11);
    chart11->addAxis(axisY11, Qt::AlignLeft);
    series11->attachAxis(axisY11);

    QValueAxis *axisX11 = new QValueAxis();
    axisX11->setLabelFormat("%d");
    chart11->addAxis(axisX11, Qt::AlignBottom);
    series11->attachAxis(axisX11);

    chart11->legend()->setVisible(true);
    chart11->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView11 = new QChartView(chart11);
    chartView11->setRenderHint(QPainter::Antialiasing);

    QGridLayout *gridlayout= new QGridLayout();
    gridlayout->addWidget(chartView00,0,0);
    gridlayout->addWidget(chartView01,0,1);
    gridlayout->addWidget(chartView10,1,0);
    gridlayout->addWidget(chartView11,1,1);

    QWidget *widget = new QWidget();
    widget->setLayout(gridlayout);

    return widget;
}
