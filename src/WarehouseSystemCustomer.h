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
     * \brief Возвращает имя.
     * \return
     */
    QString name() const;
    /*!
     * \brief Возвращает ИНН.
     * \return
     */
    QString inn() const;
    /*!
     * \brief Возвращает номер телефона.
     * \return
     */
    QString phone() const;
    /*!
     * \brief Возвращает адрес.
     * \return
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

