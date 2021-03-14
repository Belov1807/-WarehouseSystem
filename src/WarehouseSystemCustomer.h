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
    WarehouseSystemCustomer(QString _name, QString _inn, QString _phone, QString _address, int _id =0);

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
    /*!
     * \brief Возвращает идентификатор.
     * \return идентификатор.
     */
    int id() const;

private:  
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
    /*!
     * \brief m_id - идентификатор.
     */
    int m_id;
};

#endif // WAREHOUSESYSTEMCUSTOMERS_H

