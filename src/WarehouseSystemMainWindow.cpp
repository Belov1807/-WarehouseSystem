#include "WarehouseSystemMainWindow.h"
#include "ui_WarehouseSystemMainWindow.h"

#include "WarehouseSystemInfoOfCompanyWidget.h"
#include "WarehouseSystemCustomersWidget.h"
#include "WarehouseSystemProductWidget.h"
#include "WarehouseSystemArrangeOrderWidget.h"

WarehouseSystemMainWindow::WarehouseSystemMainWindow(QWidget *_parent) :
    QMainWindow(_parent),
    m_ui(new Ui::WarehouseSystemMainWindow),
    m_infoOfCompanyWidget(nullptr),
    m_customersWidget(nullptr),
    m_productsWidget(nullptr)
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
    connect(m_ui->pbInfoOfCompany, SIGNAL(clicked()), this, SLOT(infoOfCompanyWidgetSlot()));
    connect(m_ui->pbCustomers, SIGNAL(clicked()), this, SLOT(customersSlot()));
    connect(m_ui->pbProducts, SIGNAL(clicked()), this, SLOT(productsSlot()));
    connect(m_ui->pbArrangeOrder, SIGNAL(clicked()), this, SLOT(arrangeOrderWidgetSlot()));

    connect(m_ui->pbExit, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemMainWindow::infoOfCompanyWidgetSlot()
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

void WarehouseSystemMainWindow::customersSlot()
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

void WarehouseSystemMainWindow::productsSlot()

{
    if (m_productsWidget == nullptr)
    {
        m_productsWidget = new WarehouseSystemProductWidget();

        m_productsWidget->show();
    }
    else if (m_productsWidget != nullptr &&
             m_productsWidget->isVisible() == false)
    {
        m_productsWidget->close();
        delete m_productsWidget;

        m_productsWidget = new WarehouseSystemProductWidget();
        m_productsWidget->show();
    }
}

void WarehouseSystemMainWindow::arrangeOrderWidgetSlot()
{
    if (m_arrangeOrderWidget == nullptr)
    {
        m_arrangeOrderWidget = new WarehouseSystemArrangeOrderWidget();

        m_arrangeOrderWidget->show();
    }
    else if (m_arrangeOrderWidget != nullptr &&
             m_arrangeOrderWidget->isVisible() == false)
    {
        m_arrangeOrderWidget->close();
        delete m_arrangeOrderWidget;

        m_arrangeOrderWidget = new WarehouseSystemArrangeOrderWidget();
        m_arrangeOrderWidget->show();
    }
}

