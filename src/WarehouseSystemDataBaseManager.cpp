#include "WarehouseSystemDataBaseManager.h"

#include "WarehouseSystemCustomer.h"
#include "WarehouseSystemProduct.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

WarehouseSystemDataBaseManager::WarehouseSystemDataBaseManager() :
    m_customersList(ListCustomer()),
    m_productsList(ListProduct())
{
    createConnection();

    setCustomersList();
    setProductsList();
}

void WarehouseSystemDataBaseManager::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./..//resources/database/WarehouseSystemDB.db3");

    if (!db.open())
    {
        QMessageBox::critical(nullptr, QObject::tr("Ошибка!"), "Не удалось открыть файл базы данных.");
        qDebug()<<db.lastError().text();
    }
}

void WarehouseSystemDataBaseManager::setCustomersList()
{
    //Осуществляем запрос
    QSqlQuery query;
    query.exec("SELECT id, name, INN, phone, address FROM customer");
    while (query.next())
    {
        WarehouseSystemCustomer *customer = new WarehouseSystemCustomer(query.value("name").toString(),
                                                                        query.value("INN").toString(),
                                                                        query.value("phone").toString(),
                                                                        query.value("address").toString(),
                                                                        query.value("id").toInt());
        m_customersList.append(customer);
    }
}

void WarehouseSystemDataBaseManager::setProductsList()
{
    //Осуществляем запрос
    QSqlQuery query;
    query.exec("SELECT id, name, count, unit_of_measure, purchase_price FROM product");

    while (query.next())
    {
        WarehouseSystemProduct *product = new WarehouseSystemProduct(query.value("id").toInt(),
                                                                     query.value("name").toString(),
                                                                     query.value("count").toDouble(),
                                                                     query.value("unit_of_measure").toBool(),
                                                                     query.value("purchase_price").toDouble());

        m_productsList.append(product);
    }
}

ListCustomer WarehouseSystemDataBaseManager::customersList()
{
    return m_customersList;
}

ListProduct WarehouseSystemDataBaseManager::productList()
{
    return m_productsList;
}

void WarehouseSystemDataBaseManager::insertCustomer(WarehouseSystemCustomer *_customer)
{
    QSqlQuery query;

    query.prepare("INSERT INTO customer (id, name, INN, phone, address)"
                           "VALUES (:id, :name, :INN, :phone, :address)");
    query.bindValue(":name", _customer->name());
    query.bindValue(":INN", _customer->inn());
    query.bindValue(":phone", _customer->phone());
    query.bindValue(":address", _customer->address());
    query.exec();
}
