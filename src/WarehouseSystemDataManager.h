#ifndef WAREHOUSESYSTEMDATAMANAGER_H
#define WAREHOUSESYSTEMDATAMANAGER_H

#include <QList>

#include "WarehouseSystemCustomer.h"

class WarehouseSystemCustomer;
class WarehouseSystemDataBaseManager;

/*!
 * \brief Класс менеджера данных.
 */
class WarehouseSystemDataManager
{
public:
    /*!
     * \brief Конструктор.
     */
    WarehouseSystemDataManager();

    /*!
     * \brief Устанавливает список покупателей.
     */
    void setCustomersList();

    /*!
     * \brief Возвращает список покупателей по индексу.
     * \param _index - индекс.
     * \return список покупателей.
     */
    WarehouseSystemCustomer* customer(int _index);

    /*!
     * \brief Возвращает количество покупателей.
     * \return количество покупателей.
     */
    int customersCount();

    /*!
     * \brief Список покупателей.
     */
    QList<WarehouseSystemCustomer*> m_customersList;

    /*!
     * \brief Менеджер БД.
     */
    WarehouseSystemDataBaseManager *m_dataBaseManager;
};

#endif // WAREHOUSESYSTEMDATAMANAGER_H
