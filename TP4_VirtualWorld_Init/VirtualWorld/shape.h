#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>

// class Shape
// {
// public:
//     QPointF pos;
//     int id;
//     QColor col;
//     static int current_id;
//     Shape() : id(current_id++) {}
//     virtual QGraphicsItem* getGraphicsItem() const = 0;
//     virtual QString type() const = 0;

// };

// class Circle : Shape
// {
// private:
//     double radius;


// public:
//     Circle();
//     Circle(QPointF, double, QColor c = QColor::fromRgb(QRandomGenerator::global()->generate()));

// };

class Shape
{
public:
    QPointF pos;
    int id;
    QColor col;
    static int current_id;
    Shape();
    Shape(QPointF pos,QColor col= QColor::fromRgb(QRandomGenerator::global()->generate()));

    virtual QGraphicsItem* getGraphicsItem() const = 0;
    virtual QString type() const = 0;
    void setPos(QPointF newPos);
    void setCol(const QColor &newCol);
    int getId() const;
    virtual void move(QPointF) = 0;
};


class Circle : public Shape
{
private:
    double radius;
public:
    Circle();
    Circle(QPointF p, double r);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;

};


class Group : public Shape
{
protected:
    QString name;
    QVector<Shape*> shapeList;
public:
    Group();
    QVector<Shape*> getList();
    void add(Shape*);
    QGraphicsItem* getGraphicsItem() const override;
    QString type() const override;

};


