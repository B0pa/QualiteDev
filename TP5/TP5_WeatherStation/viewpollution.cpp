#include "viewpollution.h"
#include <QDebug>
#include <QDateTime>


/**
 * @class ViewPollution
 * @brief The ViewPollution class provides a widget to display pollution data in a chart.
 *
 * @param dbm Database manager to retrieve pollution data.
 * @param widget Parent widget.
 */
ViewPollution::ViewPollution(DbManager* dbm, QWidget* widget) :dbm(dbm), widget(widget)
{
    series = new QLineSeries();

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Pollution forecast ( /!\\ ACTUALISER 2 FOIS /!\\ ) ");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //    chart->createDefaultAxes();
    axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("MM/dd HH:mm");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Air Quality Indice");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout *chartLayout = new QGridLayout;
    chartLayout->addWidget(chartView, 0, 0);
    chartLayout->setContentsMargins(0, 0, 0, 0);

    // update chart
    widget->setLayout(chartLayout);

    update();
}


/**
 * @brief Updates the chart with the latest pollution data.
 */

void ViewPollution::update()
{
    series->clear();

    // example on how to convert DateTime to Unix,UTC in milliseconds
    QDateTime currentdt = QDateTime::currentDateTime();
    qint64 msdt = currentdt.toMSecsSinceEpoch();
    qDebug() << currentdt << " " << QDateTime::fromMSecsSinceEpoch(msdt);

    // generate some mock values
    // get current time, and add 1 hour (3600000ms) to get next X entry
    // Warning, OpenWeatherMap provides dt in seconds
    // => so they will be registered in seconds into the DB...
    // => you will need to convert to milliseconds (*1000.) before to append

    // append first points
//    series->append(msdt, 6);
//    series->append(msdt+3600000., 4);
//    series->append(msdt+3600000.*2, 8);
//    series->append(msdt+3600000.*3, -4);
//    series->append(msdt+3600000.*4, 5);
//    // alternative to append last points, just to show both ways
//    *series << QPointF(msdt+3600000*5, 1) << QPointF(msdt+3600000*6, 3)
//            << QPointF(msdt+3600000*7, 6) << QPointF(msdt+3600000*8, 3) << QPointF(msdt+3600000*9, 2);



    QSqlQuery query;
    int cpt=0;
    if (query.exec("SELECT dt, aqi FROM pollution")) {
        while (query.next()) {
            int aqi = query.value(1).toInt();
            series->append(msdt+3600000*cpt, aqi);
            cpt++;
        }
    } else {
        qDebug() << "ERROR: " << query.lastError().text();
    }

//    QMap<int,int> values = dbm->getAllData();

//    if(values.isEmpty())return;

//    int dtMin=values.firstKey(),dtMax=values.firstKey();
//    int aqiMin=values.first(),aqiMax=values.first();

//    for(auto i = values.begin(); i !=values.cend();++i){
//        series->append(i.key()+1000,i.value());
//        if(i.key()<dtMin)dtMin=i.key();
//        if(i.key()>dtMax)dtMax=i.key();
//        if(i.value()<aqiMin)aqiMin=i.values();
//        if(i.value()>aqiMax)aqiMax=i.values();
//    }


    // Compute min,max and update axis Ranges
    // Otherwise repaint() will no update the curve ;

//    axisX->setRange( QDateTime::fromMSecsSinceEpoch(dtMin*1000),QDateTime::fromMSecsSinceEpoch(dtMax*1000));
//    axisY->setRange(aqiMin,aqiMax); //ymin,ymax (do not change for these mock values)

    QDateTime dt0;
    dt0.setMSecsSinceEpoch(msdt); //xmin for mock values
    QDateTime dt1;
    dt1.setMSecsSinceEpoch(msdt+3600000*90); //xmax
    axisX->setRange( dt0,dt1);
    axisY->setRange(-5,9); //ymin,ymax (do not change for these mock values)

    widget->repaint();
}
