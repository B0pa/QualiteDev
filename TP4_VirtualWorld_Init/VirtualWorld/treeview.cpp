#include "treeview.h"

TreeView::TreeView(ShapeManager* sm, QTreeWidget* tw) : Observer(), shapeManager(sm), treeview(tw)
{}

void TreeView::updateModel()
{
    // Clear Treeview
    treeview->clear();

    // Generate Data
    QStringList labels;
    labels << "id" << "type";
    treeview->setHeaderLabels(labels);

    QVector<Shape*> shapes = shapeManager->getShapes();
    for (Shape* shape : shapes)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(treeview);
        item->setText(0, QString::number(shape->getId()));
        item->setText(1, shape->type());


        QTreeWidgetItem* itemChild1 = new QTreeWidgetItem(item);
        itemChild1->setText(0, "ChildId1");
        itemChild1->setText(1, "ChildType1");

        QTreeWidgetItem* itemChild2 = new QTreeWidgetItem(item);
        itemChild2->setText(0, "ChildId2");
        itemChild2->setText(1, "ChildType2");
    }
}
