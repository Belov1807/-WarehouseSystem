#include "WarehouseSystemCustomersTableModel.h"

#include "WarehouseSystemDataManager.h"

WarehouseSystemCustomersTableModel::WarehouseSystemCustomersTableModel() :
    m_dataManager(new WarehouseSystemDataManager())
{
}

WarehouseSystemCustomersTableModel::~WarehouseSystemCustomersTableModel()
{
    delete m_dataManager;
}

int WarehouseSystemCustomersTableModel::rowCount(const QModelIndex &_parent) const
{
    return  m_dataManager->customersCount();
}

int WarehouseSystemCustomersTableModel::columnCount(const QModelIndex &_parent) const
{
    return columnsCount;
}

QVariant WarehouseSystemCustomersTableModel::data(const QModelIndex &_index, int _role) const
{
    if (!_index.isValid())
    {
        return QVariant();
    }

    if (_role == Qt::DisplayRole)
    {
        int idCustomer = m_dataManager->idCustomerByIndex(_index.row());

        if (_index.column() == nameColumn)
        {
            return m_dataManager->nameCustomerById(idCustomer);
        }
        if (_index.column() == innColumn)
        {
            return m_dataManager->innCustomerById(idCustomer);
        }
        if (_index.column() == phoneColumn)
        {
            return m_dataManager->phoneCustomerById(idCustomer);
        }
        if (_index.column() == addressColumn)
        {
            return m_dataManager->addressCustomerById(idCustomer);
        }
    }
    return QVariant();
}

QVariant WarehouseSystemCustomersTableModel::headerData(int _section,
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
            return "Наименование";
        }
        if (_section == innColumn)
        {
            return "ИНН";
        }
        if (_section == phoneColumn)
        {
            return "Телефон";
        }
        if (_section == addressColumn)
        {
            return "Адрес";
        }
    }
    return QVariant();
}

void  WarehouseSystemCustomersTableModel::removeCustomer(const QModelIndex &_index)
{
    if (_index.isValid())
    {
        int id = m_dataManager->idCustomerByIndex(_index.row());
        m_dataManager->deleteCustomer(id);
    }
}

