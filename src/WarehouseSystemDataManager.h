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
     * \brief Возвращает список идентификаторов всей продукции.
     * \return список идентификаторов всей продукции.
     */
    QList<int> idProductList() const;
    /*!
     * \brief Возвращает идентификатор продукции по индексу.
     * \param index - индекс.
     * \return идентификатор продукции по индексу.
     */
    int idProductByIndex(int _index);
    /*!
     * \brief Возвращает имя продукции по идентификатору.
     * \param _id - идентификатор.
     * \return имя продукции по идентификатору.
     */
    QString nameProductById(int _id) const;
    /*!
     * \brief Возвращает количество подукции о идентификатору.
     * \param _id - идентификатор.
     * \return количество подукции о идентификатору.
     */
    double countProductById(int _id) const;
    /*!
     * \brief Возвращает ед. измерения. подукции о идентификатору.
     * \param _id - идентификатор.
     * \return ед. измерения. подукции о идентификатору.
     */
    QString unitOfMeasureProductById(int _id) const;
    /*!
     * \brief Возвращает цену закупки подукции о идентификатору.
     * \param _id - идентификатор.
     * \return цена закупки подукции о идентификатору.
     */
    double purchasePriceProductById(int _id) const;

    /*!
     * \brief Возвращает список идентификаторов всех покупателей.
     * \return список идентификаторов всех покупателей.
     */
    QList<int> idCustomersList() const;
    /*!
     * \brief Возвращает идентификатор покупателя по индексу.
     * \param index - индекс.
     * \return идентификатор покупателя по индексу.
     */
    int idCustomerByIndex(int _index);
    /*!
     * \brief Возвращает имя покупателя по идентификатору.
     * \param _id - идентификатор.
     * \return имя покупателя.
     */
    QString nameCustomerById(int _id) const;
    /*!
     * \brief Возвращает ИНН покупателя по идентификатору.
     * \param _id - идентификатор.
     * \return ИНН покупателя.
     */
    QString innCustomerById(int _id) const;
    /*!
     * \brief Возвращает номер телефона покупателя по идентификатору.
     * \param _id - идентификатор.
     * \return номер телефона покупателя.
     */
    QString phoneCustomerById(int _id) const;
    /*!
     * \brief Возвращает адрес покупателя по идентификатору.
     * \param _id - идентификатор.
     * \return адрес покупателя.
     */
    QString addressCustomerById(int _id) const;

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

private:
    /*!
     * \brief Устанавливает список покупателей.
     */
    void setCustomers();
    /*!
     * \brief Устанавливает продукцию.
     */
    void setProducts();

    /*!
     * \brief Менеджер БД.
     */
    WarehouseSystemDataBaseManager *m_dataBaseManager;

    /*!
     * \brief Список идентификаторов всех продуктов.
     */
    QList<int> m_idProductsList;
    /*!
     * \brief Список идентификаторов всех покупателей.
     */
    QList<int> m_idCustomersList;

    /*!
     * \brief словарь продукции(идентификатор-продукт).
     */
    QMap<int, WarehouseSystemProduct*> m_productsMap;
    /*!
     * \brief словарь покупателей(идентификатор-покупатель).
     */
    QMap<int, WarehouseSystemCustomer*> m_customersMap;
};

#endif // WAREHOUSESYSTEMDATAMANAGER_H
