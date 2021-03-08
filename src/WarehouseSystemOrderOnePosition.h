#ifndef WAREHOUSESYSTEMORDERONEPOSITION_H
#define WAREHOUSESYSTEMORDERONEPOSITION_H

#include <QString>

class WarehouseSystemProduct;
class WarehouseSystemDataManager;

/*!
 * \brief Класс ондой позиции заказа.
 */
class WarehouseSystemOrderOnePosition
{
public:
    /*!
     * \brief Конструктор.
     * \param _id - идентификатор продукции.
     */
    WarehouseSystemOrderOnePosition(int _id);

    /*!
     * \brief Устанавливает количество продукции.
     * \param _productCount - количество продукции.
     */
    void setProductCount(double _productCount);

    /*!
     * \brief Расчет стоимости.
     */
    void calculationOfTheCost();

    /*!
     * \brief Возвращает общую стоимость.
     * \return общая стоимость.
     */
    double totalCost() const;

    /*!
     * \brief Возвращает информацию.
     * \return информация.
     */
    QString info() const;

private:
    int m_idProduct;

    /*!
     * \brief Продукция.
     */
    WarehouseSystemProduct *m_product;
    /*!
     * \brief Количество продукции.
     */
    double m_productCount;

    /*!
     * \brief Стоимость.
     */
    double m_theCost;

    /*!
     * \brief Менеджер данных.
     */
    WarehouseSystemDataManager *m_dataManager;
};

#endif // WAREHOUSESYSTEMORDERONEPOSITION_H
