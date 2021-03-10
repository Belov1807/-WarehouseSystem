#include "WarehouseSystemCustomersWidget.h"
#include "ui_WarehouseSystemCustomersWidget.h"

#include "WarehouseSystemCustomersTableModel.h"
#include "WarehouseSystemAddCustomerDialog.h"

WarehouseSystemCustomersWidget::WarehouseSystemCustomersWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::WarehouseSystemCustomersWidget),
    m_addCustomerDialog(nullptr)
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemCustomersWidget::~WarehouseSystemCustomersWidget()
{
    delete m_ui;
}

void WarehouseSystemCustomersWidget::prepareConnections()
{
    connect(m_ui->pbAddCustomer, SIGNAL(clicked()), this, SLOT(addCustomerDialogSlot()));

    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemCustomersWidget::prepareUi()
{
    WarehouseSystemCustomersTableModel *model = new WarehouseSystemCustomersTableModel();

    m_ui->tvCustomers->setModel(model);
    //Растягивает ширину столбцов на всю длину окна.
    m_ui->tvCustomers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void WarehouseSystemCustomersWidget::addCustomerDialogSlot()
{
    if (m_addCustomerDialog == nullptr)
    {
        m_addCustomerDialog = new WarehouseSystemAddCustomerDialog();

        m_addCustomerDialog->show();
    }
    else if (m_addCustomerDialog != nullptr &&
             m_addCustomerDialog->isVisible() == false)
    {
        m_addCustomerDialog->close();
        delete m_addCustomerDialog;

        m_addCustomerDialog = new WarehouseSystemAddCustomerDialog();
        m_addCustomerDialog->show();
    }
}
