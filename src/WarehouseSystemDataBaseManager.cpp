#include "WarehouseSystemDataBaseManager.h"

#include "WarehouseSystemCustomer.h"
#include "WarehouseSystemProduct.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

WarehouseSystemDataBaseManager::WarehouseSystemDataBaseManager()
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
        QMessageBox::critical(0, QObject::tr("Ошибка!"), "Не удалось открыть файл базы данных.");
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
        WarehouseSystemCustomer *customer = new WarehouseSystemCustomer(query.value("id").toInt(),
                                                                        query.value("name").toString(),
                                                                        query.value("INN").toString(),
                                                                        query.value("phone").toString(),
                                                                        query.value("address").toString());


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

QList<WarehouseSystemCustomer*> WarehouseSystemDataBaseManager::customersList()
{
    return m_customersList;
}

QList<WarehouseSystemProduct*> WarehouseSystemDataBaseManager::productList()
{
    return m_productsList;
}
