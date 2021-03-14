#ifndef WAREHOUSESYSTEMCUSTOMERSWIDGET_H
#define WAREHOUSESYSTEMCUSTOMERSWIDGET_H

#include <QWidget>

class WarehouseSystemCustomersTableModel;
class WarehouseSystemAddCustomerDialog;

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

private slots:
    /*!
     * \brief Слот открытия диалога добавления нового покупателя.
     */
    void addCustomerDialogSlot();
    /*!
     * \brief Слот обновления табличной модели.
     */
    void updateTableSlot();

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
     * \brief Устанавливает табличную модель.
     */
    void setTable();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemCustomersWidget *m_ui;

    /*!
     * \brief Диалог добавления нового покупателя.
     */
    WarehouseSystemAddCustomerDialog *m_addCustomerDialog;
    /*!
     * \brief Табличная модель
     */
    WarehouseSystemCustomersTableModel *m_model;
};

#endif // WAREHOUSESYSTEMCUSTOMERSWIDGET_H
