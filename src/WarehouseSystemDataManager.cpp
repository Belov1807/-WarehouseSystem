#include "WarehouseSystemDataManager.h"

#include "WarehouseSystemDataBaseManager.h"
#include "WarehouseSystemCustomer.h"
#include "WarehouseSystemProduct.h"

WarehouseSystemDataManager::WarehouseSystemDataManager() :
    m_dataBaseManager(new WarehouseSystemDataBaseManager)
{
    setCustomersList();
    setProductsList();
}

void WarehouseSystemDataManager::setCustomersList()
{
    m_customersList.append(m_dataBaseManager->customersList());
}

void WarehouseSystemDataManager::setProductsList()
{
    m_productsList.append(m_dataBaseManager->productList());
}

int WarehouseSystemDataManager::customersCount()
{
    return m_customersList.count();
}

int WarehouseSystemDataManager::productsCount()
{
    return m_productsList.count();
}

WarehouseSystemCustomer* WarehouseSystemDataManager::customerAt(int _index)
{
    return m_customersList.at(_index);
}

WarehouseSystemProduct* WarehouseSystemDataManager::productAt(int _index)
{
    return m_productsList.at(_index);
}



