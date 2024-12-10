#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_virtualworld.h"
#include "paintview.h"
#include "treeview.h"

class VirtualWorld : public QMainWindow
{
    Q_OBJECT

public:
    VirtualWorld(QWidget* parent = nullptr, ShapeManager* = nullptr);
    ~VirtualWorld();

public slots:
    void addShape();
    void removeShape();
    void addGroup();
    void removeGroup();

private:
    Ui::VirtualWorldClass ui;
    PaintView* paintview;
    ShapeManager* shapeManager;
    TreeView* treeview;
};
