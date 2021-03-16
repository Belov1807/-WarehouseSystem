#ifndef WAREHOUSESYSTEMPRODUCT_H
#define WAREHOUSESYSTEMPRODUCT_H

#include <QString>

/*!
 * \brief Класс продукции.
 */
class WarehouseSystemProduct
{
public:
    /*!
     * \brief Конструктор.
     * \param _id - идентификатор.
     * \param _name - название.
     * \param _count - количество.
     * \param _unitOfMeasure - ед. измерения.
     * \param _purchasePrice - цена закупки.
     */
    WarehouseSystemProduct(QString _name, double _count, bool _unitOfMeasure, double _purchasePrice, int _id = 0);

    /*!
     * \brief Возвращает идентификатор.
     * \return идентификатор.
     */
    int id() const;
    /*!
     * \brief Возвращает название.
     * \return название продукции.
     */
    QString name() const;
    /*!
     * \brief Возвращает количество.
     * \return количество продукции.
     */
    double count() const;
    /*!
     * \brief Возвращает ед. измерения.
     * \return ед. измерения продукции.
     */
    bool unitOfMeasure() const;

    /*!
     * \brief Возвращает цену закупки.
     * \return цена закупки продукции.
     */
    double purchasePrice() const;

private:
    /*!
     * \brief Название.
     */
    QString m_name;
    /*!
     * \brief Количество.
     */
    double m_count;
    /*!
     * \brief Ед. измерения.
     */
    bool m_unitOfMeasure;
    /*!
     * \brief Цена закупки.
     */
    double m_purchasePrice;
    /*!
     * \brief Идентификатор.
     */
    int m_id;

};

#endif // WAREHOUSESYSTEMPRODUCT_H
