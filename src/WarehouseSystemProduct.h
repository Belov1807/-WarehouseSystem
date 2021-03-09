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
     * \param _id - Идентификатор.
     * \param _name - Название.
     * \param _count - Количество.
     * \param _unitOfMeasure - Ед. измерения.
     * \param _purchasePrice - Цена закупки.
     */
    WarehouseSystemProduct(int _id, QString _name, double _count, bool _unitOfMeasure, double _purchasePrice);

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
    QString unitOfMeasure() const;
    /*!
     * \brief Возвращает цену закупки.
     * \return цена закупки продукции.
     */
    double purchasePrice() const;

private:
    /*!
     * \brief Идентификатор.
     */
    int m_id;
    /*!
     * \brief Название..
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
};

#endif // WAREHOUSESYSTEMPRODUCT_H
