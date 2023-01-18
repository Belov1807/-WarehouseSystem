#ifndef WAREHOUSESYSTEMARRANGEORDER_H
#define WAREHOUSESYSTEMARRANGEORDER_H

#include <QWidget>

class WarehouseSystemOrder;
class WarehouseSystemDataManager;
class WarehouseSystemAddCustomerDialog;

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

signals:
    /*!
     * \brief Сигнал закрытия виджета.
     * \param event - событие закрытия.
     */
    void closeEvent(QCloseEvent *event = 0) override;

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

    /*!
     * \brief Слот выбора покупателя.
     */
    void changedCustomerSlot();
    /*!
     * \brief Слот открытия диалога добавления нового покупателя.
     */
    void addCustomerDialogSlot();
    /*!
     * \brief Слот обновления комбо бокса выбора покупателя.
     */
    void updateCbCustomerSlot();
    /*!
     * \brief Слот закрытия виджета.
     */
    void closeSlot();

private:
    /*!
     * \brief Подготавливает соеденения.
     */
    void prepareConnections();
    /*!
     * \brief Подготавливает отображение.
     */
    void prepareUi();

    void setItemCbCustomers();

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

    /*!
     * \brief Диалог добавления нового покупателя.
     */
    WarehouseSystemAddCustomerDialog *m_addCustomerDialog;
};

#endif // WAREHOUSESYSTEMARRANGEORDER_H
