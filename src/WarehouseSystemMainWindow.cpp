#include "WarehouseSystemMainWindow.h"
#include "ui_WarehouseSystemMainWindow.h"

#include "WarehouseSystemInfoOfCompanyWidget.h"

WarehouseSystemMainWindow::WarehouseSystemMainWindow(QWidget *_parent) :
    QMainWindow(_parent),
    m_ui(new Ui::WarehouseSystemMainWindow)
{
    m_ui->setupUi(this);

    prepareConnections();
}

WarehouseSystemMainWindow::~WarehouseSystemMainWindow()
{
    delete m_ui;
}

void WarehouseSystemMainWindow::prepareConnections()
{
    connect(m_ui->pbInfoOfCompany, SIGNAL(clicked()), this, SLOT(InfoOfCompanyWidgetSlot()));

    connect(m_ui->pbExit, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemMainWindow::InfoOfCompanyWidgetSlot()
{
    m_infoOfCompanyWidget = new WarehouseSystemInfoOfCompanyWidget();
    m_infoOfCompanyWidget->show();
}
