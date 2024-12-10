#include "shape.h"

int Shape::current_id=1;

Shape::Shape(QPointF pos,QColor col) : id(current_id++)
{
    pos = pos;
    col = QColor::fromRgb(QRandomGenerator::global()->generate());

}



Circle::Circle(QPointF p, double r): Shape(p,col)
{
    radius = r;
}


QGraphicsItem* Circle::getGraphicsItem() const
{
    // Note: handling Color by creating an inherited QGraphicsCustomEllipseItem class
    // and overriding paint() method (calling setPen(pen))

    // construct Ellipse Item from the default surrounding QRectF
    QGraphicsItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2., radius*2.);
    item->setData(0,id);
    return item;
}

void Shape::setPos(QPointF newPos)
{
    pos = newPos;
}

void Shape::setCol(const QColor &newCol)
{
    col = newCol;
}

int Shape::getId() const
{
    return id;
}

QString Shape::type() const
{
    return "Shape";
}

QString Circle::type() const
{
    return "Circle";
}

Group::Group() {
    id = current_id++;
}


QGraphicsItem* Group::getGraphicsItem() const {
    QGraphicsItemGroup* item = new QGraphicsItemGroup();
    item->setData(0, id);
    for (Shape* shape : shapeList) {
        item->addToGroup(shape->getGraphicsItem());
    }
    return item;
}

QString Group::type() const {
    return "Group";
}

void Group::add(Shape* shape) {
    shapeList.append(shape);

}

QVector<Shape*> Group::getList() {
    return shapeList;
}

