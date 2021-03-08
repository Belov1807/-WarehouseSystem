#include "WarehouseSystemProductTableModel.h"

#include "WarehouseSystemProduct.h"
#include "WarehouseSystemDataManager.h"

WarehouseSystemProductTableModel::WarehouseSystemProductTableModel() :
    m_dataManager(new WarehouseSystemDataManager)
{
}

int WarehouseSystemProductTableModel::rowCount(const QModelIndex &_parent) const
{
    return  m_dataManager->productsCount();
}

int WarehouseSystemProductTableModel::columnCount(const QModelIndex &_parent) const
{
    return columnsCount;
}

QVariant WarehouseSystemProductTableModel::data(const QModelIndex &_index, int _role) const
{
    if (!_index.isValid())
    {
        return QVariant();
    }

    if (_role == Qt::DisplayRole)
    {   
        if (_index.column() == nameColumn)
        {
            return m_dataManager->nameProductById(m_dataManager->idProductByIndex(_index.row()));
        }
        if (_index.column() == countColumn)
        {
            return m_dataManager->countProductById(m_dataManager->idProductByIndex(_index.row()));
        }
        if (_index.column() == typeColumn)
        {
            return m_dataManager->unitOfMeasureProductById(m_dataManager->idProductByIndex(_index.row()));
        }
        if (_index.column() == purchasePriceColumn)
        {
            return m_dataManager->purchasePriceProductById(m_dataManager->idProductByIndex(_index.row()));
        }
    }
    return QVariant();
}

QVariant WarehouseSystemProductTableModel::headerData(int _section,
                                                      Qt::Orientation _orientation,
                                                      int _role) const
{
    if (!_role == Qt::DisplayRole)
    {
        return QVariant();
    }
    if (_orientation == Qt::Horizontal)
    {
        if (_section == nameColumn)
        {
            return "Наименование товара";
        }
        if (_section == countColumn)
        {
            return "Количество товара \nв наличии";
        }
        if (_section == typeColumn)
        {
            return "Ед. измерения";
        }
        if (_section == purchasePriceColumn)
        {
            return "Цена по закупке за \nединицу товара";
        }
    }
    return QVariant();
}
