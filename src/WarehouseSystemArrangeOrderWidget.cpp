#include "WarehouseSystemArrangeOrderWidget.h"
#include "ui_WarehouseSystemArrangeOrderWidget.h"

#include "WarehouseSystemDataManager.h"
#include "WarehouseSystemProduct.h"

WarehouseSystemArrangeOrderWidget::WarehouseSystemArrangeOrderWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::WarehouseSystemArrangeOrderWidget),
    m_dataManager(new WarehouseSystemDataManager)
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemArrangeOrderWidget::~WarehouseSystemArrangeOrderWidget()
{
    delete m_ui;
}

void WarehouseSystemArrangeOrderWidget::prepareConnections()
{
    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}


void WarehouseSystemArrangeOrderWidget::prepareUi()
{
    m_ui->cbProducts->addItem(" ");
    for (int i = 0; i < m_dataManager->productsCount(); i++)
    {
        m_ui->cbProducts->addItem(m_dataManager->productAt(i)->name());
    }
}

