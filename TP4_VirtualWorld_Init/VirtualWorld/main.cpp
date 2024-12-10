#include "virtualworld.h"
#include "shapemanager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ShapeManager* sm = new ShapeManager;
    VirtualWorld w(nullptr, sm);
    w.show();
    return a.exec();
}
