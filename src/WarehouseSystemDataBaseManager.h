#ifndef WAREHOUSESYSTEMDATABASE_H
#define WAREHOUSESYSTEMDATABASE_H

#include <QList>
#include <QSqlDatabase>

class WarehouseSystemCustomer;
class WarehouseSystemProduct;

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
    /*!
     * \brief Возвращает список продукции.
     * \return список продукции.
     */
    QList<WarehouseSystemProduct*> productList();


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
     * \brief Устанавливает список продукции из БД.
     */
    void setProductsList();

    /*!
     * \brief Список покупателей.
     */
    QList<WarehouseSystemCustomer*> m_customersList;
    /*!
     * \brief Список продукции.
     */
    QList<WarehouseSystemProduct*> m_productsList;
};

#endif // WAREHOUSESYSTEMDATABASE_H
