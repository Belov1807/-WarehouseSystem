#ifndef WAREHOUSESYSTEMARRANGEORDER_H
#define WAREHOUSESYSTEMARRANGEORDER_H

#include <QWidget>

class WarehouseSystemOrder;
class WarehouseSystemDataManager;

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

private slots:
    /*!
     * \brief Слот выбора продукта.
     */
    void changedProductSlot();
    /*!
     * \brief Слот изменения количества продукции.
     */
    void productsCountChangeSlot();
    /*!
     * \brief Слот добавления продукции.
     */
    void addProductSlot();

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

    /*!
     * \brief Заказ.
     */
    WarehouseSystemOrder *m_order;
};

#endif // WAREHOUSESYSTEMARRANGEORDER_H
