#ifndef WAREHOUSESYSTEMARRANGEORDER_H
#define WAREHOUSESYSTEMARRANGEORDER_H

#include <QWidget>

class WarehouseSystemDataManager;
class WarehouseSystemProduct;

namespace Ui {
class WarehouseSystemArrangeOrderWidget;
}

/*!
 * \brief Класс виджета оформления заказа.
 */
class WarehouseSystemArrangeOrderWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit WarehouseSystemArrangeOrderWidget(QWidget *_parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemArrangeOrderWidget();

private:
    /*!
     * \brief Подготавливает соеденения.
     */
    void prepareConnections();
    /*!
     * \brief Подготавливает отображение.
     */
    void prepareUi();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemArrangeOrderWidget *m_ui;

    /*!
     * \brief Менеджер данных.
     */
    WarehouseSystemDataManager *m_dataManager;
};

#endif // WAREHOUSESYSTEMARRANGEORDER_H
