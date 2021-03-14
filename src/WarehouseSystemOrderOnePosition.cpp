#include "WarehouseSystemOrderOnePosition.h"

#include "WarehouseSystemProduct.h"
#include "WarehouseSystemDataManager.h"

WarehouseSystemOrderOnePosition::WarehouseSystemOrderOnePosition(int _id) :
    m_idProduct(_id),
    m_productCount(0),
    m_theCost(0),
    m_dataManager(new WarehouseSystemDataManager())
{
}

WarehouseSystemOrderOnePosition::~WarehouseSystemOrderOnePosition()
{
    delete m_dataManager;
}

void WarehouseSystemOrderOnePosition::setProductCount(double _productCount)
{
    m_productCount = _productCount;

    calculationOfTheCost();
}
void WarehouseSystemOrderOnePosition::calculationOfTheCost()
{
    // Цена закупки продукции выбранного вида.
    double purchasePrice = m_dataManager->purchasePriceProductById(m_idProduct);
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

    info.append(m_dataManager->nameProductById(m_idProduct) + " x " +
                QString::number(m_productCount) + " " +
                m_dataManager->unitOfMeasureProductById(m_idProduct) + " - " +
                QString::number(m_theCost) + " Р.");

    return info;
}
