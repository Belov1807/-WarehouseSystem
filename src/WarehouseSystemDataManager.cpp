#include "WarehouseSystemDataManager.h"

#include "WarehouseSystemDataBaseManager.h"

WarehouseSystemDataManager::WarehouseSystemDataManager() :
    m_dataBaseManager(new WarehouseSystemDataBaseManager)
{
    setCustomersList();
}

void WarehouseSystemDataManager::setCustomersList()
{
    m_customersList.append(m_dataBaseManager->customersList());
}


int WarehouseSystemDataManager::customersCount()
{
    return m_customersList.count();
}

WarehouseSystemCustomer* WarehouseSystemDataManager::customer(int _index)
{
    return m_customersList.at(_index);
}



