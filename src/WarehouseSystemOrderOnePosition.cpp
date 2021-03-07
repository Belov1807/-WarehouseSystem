#include "WarehouseSystemOrderOnePosition.h"

#include "WarehouseSystemProduct.h"

WarehouseSystemOrderOnePosition::WarehouseSystemOrderOnePosition(WarehouseSystemProduct *_product) :
    m_product(_product),
    m_productCount(0),
    m_theCost(0)
{
}

void WarehouseSystemOrderOnePosition::setProductCount(double _productCount)
{
    m_productCount = _productCount;
}

void WarehouseSystemOrderOnePosition::calculationOfTheCost()
{
    // Выбранная продукция.
    //WarehouseSystemProduct *changedProduct = m_dataManager->productAt(m_ui->cbProducts->currentIndex() - 1);
    // Цена закупки продукции выбранного вида.
    double purchasePrice = m_product->purchasePrice();
    // Количество продукции выбранного вида.
    //m_changedCountProduct;
    // Коээфицент прибыли.
    double profitRatio = purchasePrice * 0.1;
    // Коэффицент скидки.
    double discountRate = 0.9;
    // Ставка НДС.
    double NDS_Rate = 0.18;
    // НДС в рублях за выбранный вид продукции.
    double NDS = (purchasePrice + profitRatio * discountRate) * NDS_Rate;
    // Итоговая сумма за продукцию выбранного вида (одна позиция).
    m_theCost = (purchasePrice + profitRatio * discountRate + NDS) * m_productCount;
}

double WarehouseSystemOrderOnePosition::totalCost() const
{
    return m_theCost;
}

QString WarehouseSystemOrderOnePosition::info() const
{
    QString info = QString();

    info.append(m_product->name() + " x " +
                             QString::number(m_productCount) + " " +
                             m_product->unitOfMeasure() + " - " +
                             QString::number(m_theCost) + " Р.");

    return info;
}
