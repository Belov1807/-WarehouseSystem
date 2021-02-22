#ifndef WAREHOUSESYSTEMDATABASE_H
#define WAREHOUSESYSTEMDATABASE_H

#include <QList>
#include <QSqlDatabase>

class WarehouseSystemCustomer;

/*!
 * \brief Класс менеджера базы данных.
 */
class WarehouseSystemDataBaseManager
{
public:
    /*!
     * \brief Конструктор.
     */
    WarehouseSystemDataBaseManager();

    /*!
     * \brief Возвращает список покупателей.
     * \return список покупателей.
     */
    QList<WarehouseSystemCustomer*> customersList();

private:

    /*!
     * \brief Подключение к БД.
     *
     */
    void createConnection();

    /*!
     * \brief Устанавливает список покупателей из БД.
     */
    void setCustomersList();

    /*!
     * \brief Список покупателей.
     */
    QList<WarehouseSystemCustomer*> m_customersList;
};

#endif // WAREHOUSESYSTEMDATABASE_H
