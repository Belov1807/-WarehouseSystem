#ifndef WAREHOUSESYSTEMCUSTOMERS_H
#define WAREHOUSESYSTEMCUSTOMERS_H

#include <QString>

/*!
 * \brief Класс покупателя.
 */
class WarehouseSystemCustomer
{
public:
    /*!
     * \brief Конструктор.
     * \param _id - идентификатор.
     * \param _name - имя.
     * \param _inn - ИНН.
     * \param _phone - номер телефона.
     * \param _address - адрес.
     */
    WarehouseSystemCustomer(int _id, QString _name, QString _inn, QString _phone, QString _address);

    /*!
     * \brief Возвращает идентификатор.
     * \return идентификатор.
     */
    int id() const;
    /*!
     * \brief Возвращает имя.
     * \return имя покупателя.
     */
    QString name() const;
    /*!
     * \brief Возвращает ИНН.
     * \return ИНН покупателя.
     */
    QString inn() const;
    /*!
     * \brief Возвращает номер телефона.
     * \return номер телефона покупателя.
     */
    QString phone() const;
    /*!
     * \brief Возвращает адрес.
     * \return адрес покупателя.
     */
    QString address() const;

private:
    /*!
     * \brief m_id - идентификатор.
     */
    int m_id;
    /*!
     * \brief m_name - имя.
     */
    QString m_name;
    /*!
     * \brief m_inn - ИНН.
     */
    QString m_inn;
    /*!
     * \brief m_phone - телефон.
     */
    QString m_phone;
    /*!
     * \brief m_address - адрес.
     */
    QString m_address;
};

#endif // WAREHOUSESYSTEMCUSTOMERS_H

