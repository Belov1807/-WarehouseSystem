#ifndef WAREHOUSESYSTEMMAINWINDOW_H
#define WAREHOUSESYSTEMMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WarehouseSystemMainWindow; }
QT_END_NAMESPACE

class WarehouseSystemMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    WarehouseSystemMainWindow(QWidget *parent = nullptr);
    ~WarehouseSystemMainWindow();

private:
    Ui::WarehouseSystemMainWindow *ui;
};
#endif // WAREHOUSESYSTEMMAINWINDOW_H
