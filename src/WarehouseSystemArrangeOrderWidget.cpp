#include "WarehouseSystemArrangeOrderWidget.h"
#include "ui_WarehouseSystemArrangeOrderWidget.h"

#include "WarehouseSystemOrder.h"
#include "WarehouseSystemDataManager.h"

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
    connect(m_ui->sbProductsCount, SIGNAL(valueChanged(int)), this, SLOT(productsCountChangeSlot()));
    connect(m_ui->pbAddProduct, SIGNAL(clicked()), this, SLOT(addProductSlot()));

    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}


void WarehouseSystemArrangeOrderWidget::prepareUi()
{
    m_ui->sbProductsCount->setEnabled(false);
    m_ui->sbProductsCount->setValue(0);

    m_ui->lePositionCost->setReadOnly(true);
    m_ui->lePositionCost->setEnabled(false);

    m_ui->leTotalCost->setReadOnly(true);
    m_ui->leTotalCost->setEnabled(false);
    m_ui->lChangedProduct->setVisible(false);
    m_ui->pbAddProduct->setEnabled(false);

    m_ui->pbArrangeOrder->setEnabled(false);

    m_ui->cbProducts->addItem(QString());

    foreach (auto idProduct, m_dataManager->idProductList())
    {
        QVariant idProductVariant = QVariant::fromValue(idProduct);
        m_ui->cbProducts->addItem(m_dataManager->nameProductById(idProduct), idProductVariant);
    }
}

void WarehouseSystemArrangeOrderWidget::changedProductSlot()
{
    int idCurrentProduct = m_ui->cbProducts->itemData(m_ui->cbProducts->currentIndex()).toInt();

    if (m_ui->cbProducts->currentIndex() != 0)
    {
        m_order->setChangedProduct(idCurrentProduct);
    }


    if (m_ui->cbProducts->currentIndex() != 0)
    {
        m_ui->sbProductsCount->setEnabled(true);

        m_order->setChangedProductCount(m_ui->sbProductsCount->text().toDouble());
        m_ui->lePositionCost->setText(QString::number(m_order->positionCost()));

        m_ui->sbProductsCount->setMaximum(m_dataManager->countProductById(idCurrentProduct));
        m_ui->lProductsCountUnit->setText(m_dataManager->unitOfMeasureProductById(idCurrentProduct));
    }
    else
    {
        m_ui->sbProductsCount->setEnabled(false);
        m_ui->lePositionCost->clear();
        m_ui->lePositionCost->setEnabled(false);
        m_ui->leTotalCost->setEnabled(false);
        m_ui->sbProductsCount->setValue(0);
        m_ui->pbAddProduct->setEnabled(false);
    }
}
void WarehouseSystemArrangeOrderWidget::productsCountChangeSlot()
{
    if (m_ui->cbProducts->currentIndex() != 0)
    {
        m_order->setChangedProductCount(m_ui->sbProductsCount->text().toDouble());
        m_ui->lePositionCost->setEnabled(true);
        m_ui->lePositionCost->setText(QString::number(m_order->positionCost()));
    }
    m_ui->pbAddProduct->setEnabled(true);
}

void WarehouseSystemArrangeOrderWidget::addProductSlot()
{
    m_order->addPosition();

    m_ui->lChangedProduct->setVisible(true);
    m_ui->lChangedProduct->setText(m_order->infoProductsList());

    m_ui->cbProducts->removeItem(m_ui->cbProducts->currentIndex());
    m_ui->cbProducts->setCurrentIndex(0);

    m_ui->lePositionCost->setEnabled(false);
    m_ui->leTotalCost->setEnabled(true);
    m_ui->leTotalCost->setText(QString::number(m_order->totalCost()));
    m_ui->sbProductsCount->setValue(0);

    m_ui->sbProductsCount->setEnabled(false);
    m_ui->pbAddProduct->setEnabled(false);

    m_ui->pbArrangeOrder->setEnabled(true);
}
