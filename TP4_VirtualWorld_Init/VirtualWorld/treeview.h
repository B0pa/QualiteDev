#pragma once
#include "shapemanager.h"
#include "controller.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTreeWidget>

class TreeView : public Observer
{
private:
    ShapeManager* shapeManager;
    QTreeWidget* treeview;

public:
    TreeView(ShapeManager* = nullptr, QTreeWidget* = nullptr);

    void updateModel() override;
};
