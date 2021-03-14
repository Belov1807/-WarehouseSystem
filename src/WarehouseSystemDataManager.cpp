#include "WarehouseSystemDataManager.h"

#include "WarehouseSystemDataBaseManager.h"
#include "WarehouseSystemCustomer.h"
#include "WarehouseSystemProduct.h"

WarehouseSystemDataManager::WarehouseSystemDataManager() :
    m_dataBaseManager(new WarehouseSystemDataBaseManager()),
    m_idProductsList(IntList()),
    m_idCustomersList(IntList()),
    m_productsMap(MapIdProduct()),
    m_customersMap(MapIdCustomer())
{
    setCustomers();
    setProducts();
}

WarehouseSystemDataManager::~WarehouseSystemDataManager()
{
    delete m_dataBaseManager;
}

void WarehouseSystemDataManager::setCustomers()
{
    foreach (auto customer, m_dataBaseManager->customersList())
    {
        m_customersMap.insert(customer->id(), customer);
    }
    m_idCustomersList.append(m_customersMap.keys());
}

void WarehouseSystemDataManager::setProducts()
{
    foreach (auto product, m_dataBaseManager->productList())
    {
        m_productsMap.insert(product->id(), product);
    }
    m_idProductsList.append(m_productsMap.keys());
}

int WarehouseSystemDataManager::customersCount() const
{
    return m_customersMap.count();
}

int WarehouseSystemDataManager::productsCount() const
{
    return m_productsMap.count();
}

IntList WarehouseSystemDataManager::idProductList() const
{
    return m_idProductsList;
}

int WarehouseSystemDataManager::idProductByIndex(int _index) const
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

IntList WarehouseSystemDataManager::idCustomersList() const
{
    return m_idCustomersList;
}

int WarehouseSystemDataManager::idCustomerByIndex(int _index) const
{
    return m_idCustomersList.at(_index);
}

QString WarehouseSystemDataManager::nameCustomerById(int _id) const
{
    return m_customersMap.value(_id)->name();
}

QString WarehouseSystemDataManager::innCustomerById(int _id) const
{
    return m_customersMap.value(_id)->inn();
}

QString WarehouseSystemDataManager::phoneCustomerById(int _id) const
{
    return m_customersMap.value(_id)->phone();
}

QString WarehouseSystemDataManager::addressCustomerById(int _id) const
{
    return m_customersMap.value(_id)->address();
}

void WarehouseSystemDataManager::addCustomer(QString _name, QString _inn, 
                                             QString _phone, QString _address)
{
    WarehouseSystemCustomer *customer = new WarehouseSystemCustomer(_name, _inn,
                                                                    _phone, _address);

    m_dataBaseManager->insertCustomer(customer);
}
