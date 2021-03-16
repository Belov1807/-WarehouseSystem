#include "WarehouseSystemProduct.h"

WarehouseSystemProduct::WarehouseSystemProduct(QString _name, double _count, bool _unitOfMeasure, double _purchasePrice, int _id) :
    m_name(_name),
    m_count(_count),
    m_unitOfMeasure(_unitOfMeasure),
    m_purchasePrice(_purchasePrice),
    m_id(_id)
{
}

int WarehouseSystemProduct::id() const
{
    return m_id;
}

QString WarehouseSystemProduct::name() const
{
    return m_name;
}

double WarehouseSystemProduct::count() const
{
    return m_count;
}

bool WarehouseSystemProduct::unitOfMeasure() const
{
    return m_unitOfMeasure;
}
double WarehouseSystemProduct::purchasePrice() const
{
    return m_purchasePrice;
}
