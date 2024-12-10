#include "weatherreport.h"
#include <QDateTime>
#include <QTimeZone>

/**
 * @class WeatherReport
 * @brief The WeatherReport class provides a model for weather reports.
 */
WeatherReport::WeatherReport()
    : temp(0.0),temp_min(0.0),temp_max(0.0),
      lon(0.0),lat(0.0)
{ }
