#ifndef WAREHOUSESYSTEMDATAMANAGER_H
#define WAREHOUSESYSTEMDATAMANAGER_H

#include <QList>

class WarehouseSystemDataBaseManager;
class WarehouseSystemCustomer;
class WarehouseSystemProduct;

/*!
 * \brief Псевдоним для списка integer.
 */
typedef QList<int> IntList;
/*!
 * \brief Псевдоним для QMap int - WarehouseSystemProduct*.
 */
typedef QMap<int, WarehouseSystemProduct*> MapIdProduct;
/*!
 * \brief Псевдоним для QMap int - WarehouseSystemCustomer*.
 */
typedef QMap<int, WarehouseSystemCustomer*> MapIdCustomer;

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
     * \brief Деструктор..
     */
    ~WarehouseSystemDataManager();

    /*!
     * \brief Возвращает список идентификаторов всей продукции.
     * \return список идентификаторов всей продукции.
     */
    IntList idProductList() const;
    /*!
     * \brief Возвращает идентификатор продукции по индексу.
     * \param index - индекс.
     * \return идентификатор продукции по индексу.
     */
    int idProductByIndex(int _index) const;
    /*!
     * \brief Возвращает имя продукции по идентификатору.
     * \param _id - идентификатор.
     * \return имя продукции по идентификатору.
     */
    QString nameProductById(int _id) const;
    /*!
     * \brief Возвращает количество продукции о идентификатору.
     * \param _id - идентификатор.
     * \return количество подукции о идентификатору.
     */
    double countProductById(int _id) const;
    /*!
     * \brief Возвращает список всех едениц измерения продукции.
     * \return список всех едених измерения продукции.
     */
    QList<QString> unitsOfMeasureProductList() const;
    /*!
     * \brief Возвращает ед. измерения. продукции о идентификатору продукции.
     * \param _id - идентификатор продукции.
     * \return ед. измерения. подукции о идентификатору.
     */
    QString unitOfMeasureProductById(int _id) const;
    /*!
     * \brief Возвращает количество ед. измерения продукции.
     * \return
     */
    int countUnitOfMeasureProduct() const;
    /*!
     * \brief Возвращает название ед. измерения продукции по индексу ед. измерения.
     * \param _index -индекс ед. измерения.
     * \return название ед. измерения продукции.
     */
    QString productUnitOfMeasureAt(int _index) const;
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
    IntList idCustomersList()const;
    /*!
     * \brief Возвращает идентификатор покупателя по индексу.
     * \param index - индекс.
     * \return идентификатор покупателя по индексу.
     */
    int idCustomerByIndex(int _index) const;
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
    int customersCount() const;
    /*!
     * \brief Возвращает количество продукции.
     * \return количество продукции.
     */
    int productsCount() const;

    /*!
     * \brief Добавляет покупателя.
     * \param _name - имя.
     * \param _inn - ИНН.
     * \param _phone - номер телефона.
     * \param _address - адрес.
     */
    void addCustomer(QString _name, QString _inn, QString _phone, QString _address);
    /*!
     * \brief Добавляет продукцию.
     * \param _name - название.
     * \param _count - количество.
     * \param _unitOfMeasure - ед. измерения.
     * \param _purchasePrice - цена закупки.
     */
    void addProduct(QString _name, double _count, bool _unitOfMeasure, double _purchasePrice);

    /*!
     * \brief Удаляет покупателя по идентификатору.
     * \param _id - идентификатор покупателя.
     */
    void deleteCustomer(int _id);
    /*!
     * \brief Удаляет продукцию из БД по идентификатору.
     * \param _id -идентификатор продукции.
     */
    void deleteProduct(int _id);

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
     * \brief Возвращает покупателя по идентфикатору.
     * \param _id - идентификатор покупателя.
     * \return покупатель.
     */
    WarehouseSystemCustomer* customerById(int _id) const;
    /*!
     * \brief Возвращает продукт по идентификатору.
     * \param _id - идентификатор продукта.
     * \return продукт.
     */
    WarehouseSystemProduct* productById(int _id) const;

    /*!
     * \brief Менеджер БД.
     */
    WarehouseSystemDataBaseManager *m_dataBaseManager;

    /*!
     * \brief Список идентификаторов всех продуктов.
     */
    IntList m_idProductsList;
    /*!
     * \brief Список идентификаторов всех покупателей.
     */
    IntList m_idCustomersList;

    /*!
     * \brief словарь продукции(идентификатор-продукт).
     */
    MapIdProduct m_productsMap;
    /*!
     * \brief словарь покупателей(идентификатор-покупатель).
     */
    MapIdCustomer m_customersMap;
};

#endif // WAREHOUSESYSTEMDATAMANAGER_H
