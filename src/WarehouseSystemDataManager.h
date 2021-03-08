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
     * \brief Возвращает покупателя по индексу.
     * \param _index - индекс.
     * \return покупатель.
     */
    WarehouseSystemCustomer* customerAt(int _index);

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
    void setCustomersList();
    /*!
     * \brief Устанавливает продукцию.
     */
    void setProducts();

    /*!
     * \brief Менеджер БД.
     */
    WarehouseSystemDataBaseManager *m_dataBaseManager;

    /*!
     * \brief Список покупателей.
     */
    QList<WarehouseSystemCustomer*> m_customersList;

    /*!
     * \brief Список идентификаторов всех продуктов.
     */
    QList<int> m_idProductsList;

    /*!
     * \brief словарь продукции(идентификатор-продукт).
     */
    QMap<int, WarehouseSystemProduct*> m_productsMap;
};

#endif // WAREHOUSESYSTEMDATAMANAGER_H
