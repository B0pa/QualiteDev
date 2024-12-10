#include "shapemanager.h"

ShapeManager::ShapeManager() : Observable(), selected(nullptr)
{}

void ShapeManager::add(Shape* shape)
{
    if (shape == nullptr) return;

    shapes.append(shape);
    notifyObserver();
}


void ShapeManager::moveShape(QPointF pos)
{
    if (selected == nullptr) return;

    selected->move(pos);
}

bool ShapeManager::selectShape(int id)
{
    selected = nullptr;
    for (Shape* shape : shapes)
    {
        if (shape->id == id)
        {
            selected = shape;
            return true;
        }
    }

    return false;
}


void ShapeManager::remove(Shape* _shape) {
    shapes.removeOne(_shape);
    notifyObserver();
}

void ShapeManager::removeGroup(Shape* _shape) {
    for (Shape* shape : _shape->getShape()) {
        shapes.append(shape);
    }
    shapes.removeOne(_shape);
    notifyObserver();
}
