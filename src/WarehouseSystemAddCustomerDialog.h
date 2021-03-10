#ifndef WAREHOUSESYSTEMADDCUSTOMERDIALOG_H
#define WAREHOUSESYSTEMADDCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class WarehouseSystemAddCustomerDialog;
}

/*!
 * \brief Класс диалога добавления нового покупателя.
 */
class WarehouseSystemAddCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit WarehouseSystemAddCustomerDialog(QWidget *_parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemAddCustomerDialog();

private slots:
    /*!
     * \brief Слот изменения маски ввода.
     */
    void changeInputMaskSlot();

    /*!
     * \brief Слот проверки введенных данных.
     */
    void checkInputSlot();

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
    Ui::WarehouseSystemAddCustomerDialog *m_ui;
};

#endif // WAREHOUSESYSTEMADDCUSTOMERDIALOG_H
