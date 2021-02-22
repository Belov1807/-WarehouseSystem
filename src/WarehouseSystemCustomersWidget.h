#ifndef WAREHOUSESYSTEMCUSTOMERSWIDGET_H
#define WAREHOUSESYSTEMCUSTOMERSWIDGET_H

#include <QWidget>

class WarehouseSystemCustomersTableModel;

namespace Ui {
class WarehouseSystemCustomersWidget;
}

/*!
 * \brief Класс виджета покупателей.
 */
class WarehouseSystemCustomersWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit WarehouseSystemCustomersWidget(QWidget *_parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemCustomersWidget();

private:
    /*!
     * \brief Подготавливает отображение.
     */
    void prepareUi();
    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemCustomersWidget *m_ui;
};

#endif // WAREHOUSESYSTEMCUSTOMERSWIDGET_H
