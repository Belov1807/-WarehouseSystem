#include "WarehouseSystemMainWindow.h"
#include "ui_WarehouseSystemMainWindow.h"

#include "WarehouseSystemInfoOfCompanyWidget.h"
#include "WarehouseSystemCustomersWidget.h"

WarehouseSystemMainWindow::WarehouseSystemMainWindow(QWidget *_parent) :
    QMainWindow(_parent),
    m_ui(new Ui::WarehouseSystemMainWindow),
    m_infoOfCompanyWidget(nullptr)
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
    connect(m_ui->pbCustomers, SIGNAL(clicked()), this, SLOT(CustomersSlot()));

    connect(m_ui->pbExit, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemMainWindow::InfoOfCompanyWidgetSlot()
{

    if (m_infoOfCompanyWidget == nullptr)
    {
        m_infoOfCompanyWidget = new WarehouseSystemInfoOfCompanyWidget();

        m_infoOfCompanyWidget->show();
    }
    else if (m_infoOfCompanyWidget != nullptr &&
             m_infoOfCompanyWidget->isVisible() == false)
    {
        m_infoOfCompanyWidget->close();
        delete m_infoOfCompanyWidget;

        m_infoOfCompanyWidget = new WarehouseSystemInfoOfCompanyWidget();
        m_infoOfCompanyWidget->show();
    }
}

void WarehouseSystemMainWindow::CustomersSlot()
{
    if (m_customersWidget == nullptr)
    {
        m_customersWidget = new WarehouseSystemCustomersWidget();

        m_customersWidget->show();
    }
    else if (m_customersWidget != nullptr &&
             m_customersWidget->isVisible() == false)
    {
        m_customersWidget->close();
        delete m_customersWidget;

        m_customersWidget = new WarehouseSystemCustomersWidget();
        m_customersWidget->show();
    }
}
