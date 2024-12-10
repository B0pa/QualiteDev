#include "controller.h"
#include "shapemanager.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAdd::ControllerAdd(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAdd::control(int type, QColor col)
{
    if (shapeManager == nullptr) return;

    // Add Shape
    // TODO : call Factory here!
    shapeManager->add(new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100));
    //shapeManager->add(new Circle(QPointF(0., 0.), 100.));
}

ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items)
{
    if (shapeManager == nullptr) return;

    // Move Shape
    for (QGraphicsItem* item : items)
    {
        QVariant variant = item->data(0);
        int id = variant.toInt();

        Shape* shape = shapeManager->getShape(id);
        if (shape!=nullptr)
        {
            QRectF rect = item->boundingRect();
            shape->setPos(item->scenePos() + rect.center());
            for (auto child:item->childItems())
            {
                int iid = child->data(0).toInt();
                shapeManager->getShape(iid)->setPos(child->scenePos()+child->boundingRect().center());
            }
        }
    }
    shapeManager->notifyObserver();
}


void ControllerGroup::control(QVector<QGraphicsItem*> items) {
    if (shapeManager == nullptr) return;
    QVector<Shape*> _shapes;

    for (QGraphicsItem* item : items) {
        for (Shape* shape : shapeManager->getShapes())
        {
            if (shape->id == item->data(0))
            {
                _shapes.append(shape);
            }
        }
    }

    ShapeFactory* factory = new ShapeFactory();
    Shape* shapeCreated = factory->createShape(_shapes);

    // Add Shape

    if (shapeCreated != nullptr) {
        shapeManager->add(shapeCreated);
        for (Shape* shape : _shapes) {
            shapeManager->remove(shape);
        }
    }
    delete factory;
}

void ControllerRemoveGroup::control(QVector<QGraphicsItem*> items) {
    if (shapeManager == nullptr) return;
    QVector<Shape*> _shapes;

    for (QGraphicsItem* item : items) {
        for (Shape* shape : shapeManager->getShapes())
        {
            if (shape->id == item->data(0))
            {
                shapeManager->removeGroup(shape);
                break;
            }
        }
    }

    shapeManager->notifyObserver();
}
