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
    m_productsWidget(nullptr),
    m_arrangeOrderWidget(nullptr)
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
        m_infoOfCompanyWidget = new WarehouseSystemInfoOfCompanyWidget(m_ui->widget);

        m_ui->frMain->hide();
        connect(m_infoOfCompanyWidget, SIGNAL(closeEvent()), this, SLOT(closeWindowSlot()));
    }
}

void WarehouseSystemMainWindow::customersSlot()
{
    if (m_customersWidget == nullptr)
    {
        m_customersWidget = new WarehouseSystemCustomersWidget(m_ui->widget);

        m_ui->frMain->hide();
        connect(m_customersWidget, SIGNAL(closeEvent()), this, SLOT(closeWindowSlot()));
    }
}

void WarehouseSystemMainWindow::productsSlot()

{
    if (m_productsWidget == nullptr)
    {
        m_productsWidget = new WarehouseSystemProductWidget(m_ui->widget);

        m_ui->frMain->hide();
        connect(m_productsWidget, SIGNAL(closeEvent()), this, SLOT(closeWindowSlot()));
    }
}

void WarehouseSystemMainWindow::arrangeOrderWidgetSlot()
{
    if (m_arrangeOrderWidget == nullptr)
    {
        m_arrangeOrderWidget = new WarehouseSystemArrangeOrderWidget(m_ui->widget);

        m_ui->frMain->hide();
        connect(m_arrangeOrderWidget, SIGNAL(closeEvent()), this, SLOT(closeWindowSlot()));
    }
}

void WarehouseSystemMainWindow::closeWindowSlot()
{
    QObject *senderObject = sender();

    if (senderObject == m_infoOfCompanyWidget)
    {
        delete m_infoOfCompanyWidget;
        m_infoOfCompanyWidget = nullptr;
    }
    else if (senderObject == m_customersWidget)
    {
        delete m_customersWidget;
        m_customersWidget = nullptr;
    }
    else if (senderObject == m_productsWidget)
    {
        delete m_productsWidget;
        m_productsWidget = nullptr;
    }
    else if (senderObject == m_arrangeOrderWidget)
    {
        delete m_arrangeOrderWidget;
        m_arrangeOrderWidget = nullptr;
    }

    m_ui->frMain->show();
}
