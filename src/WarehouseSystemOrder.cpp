#include "WarehouseSystemOrder.h"

#include "WarehouseSystemProduct.h"
#include "WarehouseSystemCustomer.h"
#include "WarehouseSystemOrderOnePosition.h"

WarehouseSystemOrder::WarehouseSystemOrder(int _id, WarehouseSystemCustomer *_customer) :
    m_id(_id),
    m_customer(_customer),
    m_orderPosition(nullptr)
{
}

void WarehouseSystemOrder::setChangedProduct(int _id)
{
    m_orderPosition = new WarehouseSystemOrderOnePosition(_id);
}

void WarehouseSystemOrder::setChangedProductCount(double _changedProductCount)
{
    if (m_orderPosition != nullptr)
    {
        m_orderPosition->setProductCount(_changedProductCount);
    }
}

QString WarehouseSystemOrder::infoProductsList() const
{
    QString positionsListTitle = QString();

    foreach (auto position, m_positionsList)
    {
        positionsListTitle.append(position->info());

        if (position != m_positionsList.last())
        {
            positionsListTitle.append("  +\n");
        }
    }
    return positionsListTitle;
}

double WarehouseSystemOrder::positionCost() const
{
    return m_orderPosition->totalCost();
}

void WarehouseSystemOrder::addPosition()
{
    m_positionsList.append(m_orderPosition);
}

double WarehouseSystemOrder::totalCost() const
{
    double totalCost = 0;

    foreach (auto position, m_positionsList)
    {
        totalCost += position->totalCost();
    }
    return totalCost;
}
