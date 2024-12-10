#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#pragma once
#include"shapemanager.h"
#include"controller.h"


class ShapeFactory
{
private:
         //ShapeManager* shapeManager;

public:
    ShapeFactory();
    Shape* createShape(QString&);
    Shape* createShape(QVector<Shape*>);

    static Shape* createRectCar(QString&, QPointF, double, double);
    static Shape* createCircleCar(QString&, QPointF, double);
};



#endif // SHAPEFACTORY_H
