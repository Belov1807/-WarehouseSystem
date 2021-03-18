#ifndef WAREHOUSESYSTEMDATABASE_H
#define WAREHOUSESYSTEMDATABASE_H

#include <QList>

class WarehouseSystemCustomer;
class WarehouseSystemProduct;

/*!
 * \brief Псевдоним для списка WarehouseSystemCustomer*.
 */
typedef QList<WarehouseSystemCustomer*> ListCustomer;
/*!
 * \brief Псевдоним для списка WarehouseSystemProduct*.
 */
typedef QList<WarehouseSystemProduct*> ListProduct;

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
    ListCustomer customersList();
    /*!
     * \brief Возвращает список продукции.
     * \return список продукции.
     */
    ListProduct productList();

    /*!
     * \brief Добавляет покупателя в БД.
     * \param _customer - покупатель.
     */
    void insertCustomer(WarehouseSystemCustomer *_customer);
    /*!
     * \brief Добавляет продукцию в БД.
     * \param _customer - продукция.
     */
    void insertProduct(WarehouseSystemProduct *_product);

    /*!
     * \brief Удаляет покупателя из БД по идентификатору.
     * \param _id -идентификатор покупателя.
     */
    void deleteCustomer(int _id);
    /*!
     * \brief Удаляет продукцию из БД по идентификатору.
     * \param _id -идентификатор продукции.
     */
    void deleteProduct(int _id);

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
    ListCustomer m_customersList;
    /*!
     * \brief Список продукции.
     */
    ListProduct m_productsList;
};

#endif // WAREHOUSESYSTEMDATABASE_H
