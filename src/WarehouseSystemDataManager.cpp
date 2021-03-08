#include "WarehouseSystemDataManager.h"

#include "WarehouseSystemDataBaseManager.h"
#include "WarehouseSystemCustomer.h"
#include "WarehouseSystemProduct.h"

WarehouseSystemDataManager::WarehouseSystemDataManager() :
    m_dataBaseManager(new WarehouseSystemDataBaseManager)
{
    setCustomersList();
    setProducts();
}

void WarehouseSystemDataManager::setCustomersList()
{
    m_customersList.append(m_dataBaseManager->customersList());
}

void WarehouseSystemDataManager::setProducts()
{
    foreach (auto product, m_dataBaseManager->productList())
    {
        m_productsMap.insert(product->id(), product);
    }
    m_idProductsList.append(m_productsMap.keys());
}

int WarehouseSystemDataManager::customersCount()
{
    return m_customersList.count();
}

int WarehouseSystemDataManager::productsCount()
{
    return m_productsMap.count();
}

WarehouseSystemCustomer* WarehouseSystemDataManager::customerAt(int _index)
{
    return m_customersList.at(_index);
}

QList<int> WarehouseSystemDataManager::idProductList() const
{
    return m_idProductsList;
}

int WarehouseSystemDataManager::idProductByIndex(int _index)
{
    return  m_idProductsList.at(_index);
}

QString WarehouseSystemDataManager::nameProductById(int _id) const
{
    return m_productsMap.value(_id)->name();
}

double WarehouseSystemDataManager::countProductById(int _id) const
{
    return m_productsMap.value(_id)->count();
}

QString WarehouseSystemDataManager::unitOfMeasureProductById(int _id) const
{
    return m_productsMap.value(_id)->unitOfMeasure();
}

double WarehouseSystemDataManager::purchasePriceProductById(int _id) const
{
    return m_productsMap.value(_id)->purchasePrice();
}

