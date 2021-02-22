#include "WarehouseSystemDataBaseManager.h"

#include "WarehouseSystemCustomer.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

WarehouseSystemDataBaseManager::WarehouseSystemDataBaseManager()
{
    createConnection();

    setCustomersList();
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

QList<WarehouseSystemCustomer*> WarehouseSystemDataBaseManager::customersList()
{
    return m_customersList;
}


