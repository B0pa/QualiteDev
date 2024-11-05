#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Interface (data are loaded here)
    TP3_GestionEtu w;
    w.show();

    return a.exec();
}
