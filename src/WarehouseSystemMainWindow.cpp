#include "WarehouseSystemMainWindow.h"
#include "ui_WarehouseSystemMainWindow.h"

WarehouseSystemMainWindow::WarehouseSystemMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::WarehouseSystemMainWindow)
{
    m_ui->setupUi(this);
}

WarehouseSystemMainWindow::~WarehouseSystemMainWindow()
{
    delete m_ui;
}

