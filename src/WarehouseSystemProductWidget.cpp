#include "WarehouseSystemProductWidget.h"
#include "ui_WarehouseSystemProductWidget.h"

#include "WarehouseSystemProductTableModel.h"
#include "WarehouseSystemAddProductDialog.h"

WarehouseSystemProductWidget::WarehouseSystemProductWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WarehouseSystemProductWidget),
    m_model(new WarehouseSystemProductTableModel()),
    m_addProductDialog(nullptr)
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemProductWidget::~WarehouseSystemProductWidget()
{
    delete m_ui;
    delete m_model;
}

void WarehouseSystemProductWidget::prepareConnections()
{
    connect(m_ui->pbAddProduct, SIGNAL(clicked()), this, SLOT(addProductDialogSlot()));

    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemProductWidget::prepareUi()
{
    setTable();
}

void WarehouseSystemProductWidget::addProductDialogSlot()
{
    if (m_addProductDialog == nullptr)
    {
        m_addProductDialog = new WarehouseSystemAddProductDialog();

        m_addProductDialog->show();
        connect(m_addProductDialog, SIGNAL(addProductToDBSignal()), this, SLOT(updateTableSlot()));
    }
    else if (m_addProductDialog != nullptr &&
             m_addProductDialog->isVisible() == false)
    {
        m_addProductDialog->close();
        delete m_addProductDialog;

        m_addProductDialog = new WarehouseSystemAddProductDialog();
        m_addProductDialog->show();
    }
}

void WarehouseSystemProductWidget::setTable()
{
    m_ui->tvProducts->setModel(m_model);
    //Растягивает ширину столбцов на всю длину окна.
    m_ui->tvProducts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void WarehouseSystemProductWidget::updateTableSlot()
{
    delete m_model;
    m_model = new WarehouseSystemProductTableModel();

    setTable();
}
