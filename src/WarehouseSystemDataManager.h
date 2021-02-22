#ifndef WAREHOUSESYSTEMDATAMANAGER_H
#define WAREHOUSESYSTEMDATAMANAGER_H

#include <QList>

class WarehouseSystemDataBaseManager;
class WarehouseSystemCustomer;
class WarehouseSystemProduct;

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
     * \brief Устанавливает список продукции.
     */
    void setProductsList();

    /*!
     * \brief Возвращает покупателя по индексу.
     * \param _index - индекс.
     * \return покупатель.
     */
    WarehouseSystemCustomer* customerAt(int _index);
    /*!
     * \brief Возвращает продукцию по индексу.
     * \param _index - индекс.
     * \return продукция.
     */
    WarehouseSystemProduct* productAt(int _index);

    /*!
     * \brief Возвращает количество покупателей.
     * \return количество покупателей.
     */
    int customersCount();
    /*!
     * \brief Возвращает количество продукции.
     * \return количество продукции.
     */
    int productsCount();

    /*!
     * \brief Менеджер БД.
     */
    WarehouseSystemDataBaseManager *m_dataBaseManager;

    /*!
     * \brief Список покупателей.
     */
    QList<WarehouseSystemCustomer*> m_customersList;
    /*!
     * \brief Список продукции.
     */
    QList<WarehouseSystemProduct*> m_productsList;
};

#endif // WAREHOUSESYSTEMDATAMANAGER_H
