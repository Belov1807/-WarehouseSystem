#include "WarehouseSystemCustomersWidget.h"
#include "ui_WarehouseSystemCustomersWidget.h"

#include "WarehouseSystemCustomersTableModel.h"
#include "WarehouseSystemAddCustomerDialog.h"

WarehouseSystemCustomersWidget::WarehouseSystemCustomersWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::WarehouseSystemCustomersWidget),
    m_addCustomerDialog(nullptr),
    m_model(new WarehouseSystemCustomersTableModel())
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemCustomersWidget::~WarehouseSystemCustomersWidget()
{
    delete m_ui;
    delete m_model;
}

void WarehouseSystemCustomersWidget::prepareConnections()
{
    connect(m_ui->pbAddNewCustomer, SIGNAL(clicked()), this, SLOT(addCustomerDialogSlot()));
    connect(m_ui->pbRemoveCustomer, SIGNAL(clicked()), this, SLOT(removeCustomerSlot()));

    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemCustomersWidget::prepareUi()
{
    setTable();
    m_ui->pbRemoveCustomer->setEnabled(false);
}

void WarehouseSystemCustomersWidget::addCustomerDialogSlot()
{
    if (m_addCustomerDialog == nullptr)
    {
        m_addCustomerDialog = new WarehouseSystemAddCustomerDialog();

        m_addCustomerDialog->show();
        connect(m_addCustomerDialog, SIGNAL(addCustomerToDBSignal()), this, SLOT(updateTableSlot()));
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

void WarehouseSystemCustomersWidget::setTable()
{
    m_ui->tvCustomers->setModel(m_model);
    //Растягивает ширину столбцов на всю длину окна.
    m_ui->tvCustomers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Убирает вертикальный выбор.
    m_ui->tvCustomers->verticalHeader()->hide();
    //Убирает фокус ячейки.
    m_ui->tvCustomers->setFocusPolicy(Qt::NoFocus);
    //Устанавливает выбор целой строки.
    m_ui->tvCustomers->setSelectionBehavior(QAbstractItemView::SelectRows);
    //Устанавливает единичный выбор.
    m_ui->tvCustomers->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(m_ui->tvCustomers->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(setEnabledPbRemoveCustomerSlot()));
}

void WarehouseSystemCustomersWidget::updateTableSlot()
{
    delete m_model;
    m_model = new WarehouseSystemCustomersTableModel();
    setTable();
}

void WarehouseSystemCustomersWidget::removeCustomerSlot()
{
    if (m_ui->tvCustomers->currentIndex().isValid())
    {
        m_model->removeCustomer(m_ui->tvCustomers->currentIndex());
        updateTableSlot();
    }
}

void WarehouseSystemCustomersWidget::setEnabledPbRemoveCustomerSlot()
{
    if (m_ui->tvCustomers->currentIndex().isValid())
    {
        m_ui->pbRemoveCustomer->setEnabled(true);
    }
    else
    {
        m_ui->pbRemoveCustomer->setEnabled(false);
    }
}
