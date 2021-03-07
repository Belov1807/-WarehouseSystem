#include "WarehouseSystemArrangeOrderWidget.h"
#include "ui_WarehouseSystemArrangeOrderWidget.h"

#include "WarehouseSystemOrder.h"
#include "WarehouseSystemDataManager.h"
#include "WarehouseSystemProduct.h"

WarehouseSystemArrangeOrderWidget::WarehouseSystemArrangeOrderWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::WarehouseSystemArrangeOrderWidget),
    m_dataManager(new WarehouseSystemDataManager),
    m_order(new WarehouseSystemOrder())
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
    connect(m_ui->cbProducts, SIGNAL(currentIndexChanged(int)), this, SLOT(changedProductSlot()));
    connect(m_ui->teProductsCount, SIGNAL(textChanged()), this, SLOT(productsCountChangeSlot()));
    connect(m_ui->pbAddProduct, SIGNAL(clicked()), this, SLOT(addProductSlot()));

    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));

}


void WarehouseSystemArrangeOrderWidget::prepareUi()
{
    m_ui->teTotalCost->setReadOnly(true);
    m_ui->lChangedProduct->setVisible(false);
    m_ui->pbAddProduct->setEnabled(false);

    m_ui->cbProducts->addItem(" ");
    for (int i = 0; i < m_dataManager->productsCount(); i++)
    {
        m_ui->cbProducts->addItem(m_dataManager->productAt(i)->name());
    }
}

void WarehouseSystemArrangeOrderWidget::changedProductSlot()
{
    m_order->setChangedProduct(m_dataManager->productAt(m_ui->cbProducts->currentIndex() - 1));
}

void WarehouseSystemArrangeOrderWidget::productsCountChangeSlot()
{
    if (m_ui->cbProducts->currentIndex() != 0)
    {
        m_ui->pbAddProduct->setEnabled(true);
    }
}

void WarehouseSystemArrangeOrderWidget::addProductSlot()
{
    m_order->setChangedProductCount(m_ui->teProductsCount->toPlainText().toDouble());

    m_order->addPosition();

    m_ui->lChangedProduct->setVisible(true);
    m_ui->lChangedProduct->setText(m_order->infoProductsList());

    m_ui->cbProducts->removeItem(m_ui->cbProducts->currentIndex());
    m_ui->cbProducts->setCurrentIndex(0);

    m_ui->teTotalCost->setText(QString::number(m_order->totalCost()));
    m_ui->teProductsCount->clear();

    m_ui->pbAddProduct->setEnabled(false);
}
