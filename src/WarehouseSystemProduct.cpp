#include "WarehouseSystemProduct.h"

WarehouseSystemProduct::WarehouseSystemProduct(int _id, QString _name, double _count, bool _unitOfMeasure, double _purchasePrice) :
    m_id(_id),
    m_name(_name),
    m_count(_count),
    m_unitOfMeasure(_unitOfMeasure),
    m_purchasePrice(_purchasePrice)
{
}


QString WarehouseSystemProduct::name() const
{
    return m_name;
}

double WarehouseSystemProduct::count() const
{
    return m_count;
}

QString WarehouseSystemProduct::unitOfMeasure() const
{
    if (m_unitOfMeasure)
    {
        return "шт.";
    }
    else
    {
        return "кг";
    }
}

double WarehouseSystemProduct::purchasePrice() const
{
    return m_purchasePrice;
}
