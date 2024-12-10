#include "viewreport.h"
#include "dbmanager.h"

/**
 * @class ViewReport
 * @brief The ViewReport class provides a view for weather reports.
 *
 * @param wreport Weather report model.
 * @param ui User interface for the TP5_WeatherStationClass.
 */
ViewReport::ViewReport(WeatherReport *wreport, Ui::TP5_WeatherStationClass *ui)
    : model(wreport), ui(ui)
{
    init();
    update();
}

/**
 * @brief Initializes the view by clearing all line edits.
 */
void ViewReport::init()
{
    ui->lineEdit_temp->clear();
    ui->lineEdit_temp_min->clear();
    ui->lineEdit_temp_max->clear();
    ui->lineEdit_lon->clear();
    ui->lineEdit_lat->clear();
    ui->lineEdit_description->clear();
}

/**
 * @brief Updates the view with the latest data from the model.
 */
void ViewReport::update()
{
    ui->lineEdit_description->setText(model->getDescription());
    ui->lineEdit_temp->setText(QString::number(model->getTemp()));
    ui->lineEdit_temp_min->setText(QString::number(model->getTempMin()));
    ui->lineEdit_temp_max->setText(QString::number(model->getTempMax()));
    ui->lineEdit_lon->setText(QString::number(model->getLon()));
    ui->lineEdit_lat->setText(QString::number(model->getLat()));
}
