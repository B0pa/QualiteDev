#include "shapefactory.h"
#include<iostream>
using namespace std;


ShapeFactory::ShapeFactory() { ; }


Shape* ShapeFactory::createShape(QString& shapeString) {

    QStringList liste = shapeString.split('-');
    QString shapeOnly = liste[0];

    if (shapeOnly == "Circle") {
        return new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 1, shapeString);
    }
    else if (shapeOnly == "Rectangle") {
        return new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 1, std::rand() % 100 + 1, shapeString);
    }
    else if (shapeOnly == "Square") {
        return new Square(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 1, shapeString);
    }
    else {
        cout << "No shape created" << endl;
    }
    return nullptr;
}

Shape* ShapeFactory::createShape(QVector<Shape*> _shapes) {
    Group* group = new Group();
    for (Shape* shape : _shapes) {
        group->add(shape);
    }
    return group;
}

Shape* ShapeFactory::createRectCar(QString&, QPointF, double, double)
{
    return nullptr;
}

Shape* ShapeFactory::createCircleCar(QString&, QPointF, double)
{
    return nullptr;
}
