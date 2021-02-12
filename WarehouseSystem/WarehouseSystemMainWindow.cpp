#include "WarehouseSystemMainWindow.h"
#include "ui_WarehouseSystemMainWindow.h"

WarehouseSystemMainWindow::WarehouseSystemMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WarehouseSystemMainWindow)
{
    ui->setupUi(this);
}

WarehouseSystemMainWindow::~WarehouseSystemMainWindow()
{
    delete ui;
}

