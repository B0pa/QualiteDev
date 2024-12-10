#pragma once
#include "shapemanager.h"
#include <QPointF>

class ControllerAdd
{
    ShapeManager* shapeManager;
public:
    ControllerAdd(ShapeManager* = nullptr);
    void control(int type, QColor col);
};

class ControllerMoveShape
{
    ShapeManager* shapeManager;
public:
    ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};

class ControllerGroup {
    ShapeManager* shapeManager;

public:
    ControllerGroup(ShapeManager* sm) : shapeManager(sm) { ; }
    void control(const QVector<QGraphicsItem*>);
};

class ControllerRemoveGroup {
    ShapeManager* shapeManager;

public:
    ControllerRemoveGroup(ShapeManager* sm) : shapeManager(sm) { ; }
    void control(const QVector<QGraphicsItem*>);
};
