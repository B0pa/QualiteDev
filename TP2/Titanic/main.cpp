#include "titanic.h"
#include "data.h"
#include "QDebug"
#include "QDir"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Titanic w(QDir::currentPath()+"/../../titanic.dbf");
    w.show();
    return a.exec();
}
