#include "virtualworld.h"
#include "controller.h"
#include <QDebug>

VirtualWorld::VirtualWorld(QWidget *parent, ShapeManager* sm)
    : QMainWindow(parent), shapeManager(sm)
{
    ui.setupUi(this);

    // Paint View
    paintview = new PaintView(shapeManager);
    shapeManager->addObserver(paintview);
    ui.graphicsView->setScene(paintview);
    paintview->setParent(ui.graphicsView);

    // Tree View
    treeview = new TreeView(shapeManager, ui.treeWidget);
    shapeManager->addObserver(treeview);

    // Connect buttons
    connect(ui.Object_AddButton, &QPushButton::pressed, this, &VirtualWorld::addShape);
    connect(ui.Object_GroupButton, &QPushButton::pressed, paintview, &VirtualWorld::addGroup);
    //    connect(ui.Object_UnGroupButton, &QPushButton::pressed, paintview, &PaintView::unGroupShapes);
    //    connect(ui.Object_RemoveButton, &QPushButton::pressed, paintview, &PaintView::removeShapes);

    // Handling colors here
    //    connect(ui.Object_ColorButton, &QPushButton::pressed, this, &VirtualWorld::colorShape);

}

VirtualWorld::~VirtualWorld()
{
    delete shapeManager;
}

void VirtualWorld::addShape()
{
    // TODO: transmit shape type (from QButtonGroup), for the Fabric...
    ControllerAdd(shapeManager).control(0,QColor());
}

void VirtualWorld::addGroup() {
    paintview->saveSelect();
    ControllerGroup* controller = new ControllerGroup(shapeManager);
    controller->control(paintview->getSelect());
    delete controller;
    paintview->setSelect();
}
