#include "WarehouseSystemMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WarehouseSystemMainWindow w;
    w.show();
    return a.exec();
}
