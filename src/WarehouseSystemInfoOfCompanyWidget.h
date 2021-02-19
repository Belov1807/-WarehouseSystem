#ifndef WAREHOUSESYSTEMINFOOFCOMPANYWIDGET_H
#define WAREHOUSESYSTEMINFOOFCOMPANYWIDGET_H

#include <QWidget>

namespace Ui {
class WarehouseSystemInfoOfCompanyWidget;
}

/*!
 * \brief Класс виджета информации о компании.
 */
class WarehouseSystemInfoOfCompanyWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param parent - родительский виджет.
     */
    explicit WarehouseSystemInfoOfCompanyWidget(QWidget *_parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemInfoOfCompanyWidget();

private:
    /*!
     * \brief Подготавливает соеденения.
     */
    void prepareConnections();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemInfoOfCompanyWidget *m_ui;
};

#endif // WAREHOUSESYSTEMINFOOFCOMPANYWIDGET_H
