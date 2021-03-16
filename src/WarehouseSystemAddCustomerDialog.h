#ifndef WAREHOUSESYSTEMADDCUSTOMERDIALOG_H
#define WAREHOUSESYSTEMADDCUSTOMERDIALOG_H

#include <QDialog>

class WarehouseSystemDataManager;

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

    /*!
     * \brief Слот добавления нового покупателя.
     */
    void addNewCustomerSlot();

signals:
    /*!
     * \brief Сигнал добавления нового покупателя в базу данных.
     */
    void addCustomerToDBSignal();

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
     * \brief Устанавливает начальное значение маски ввода номера телефона.
     */
    void setStartedIputMaskPhone();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemAddCustomerDialog *m_ui;

    /*!
     * \brief Менеджер данных.
     */
    WarehouseSystemDataManager *m_dataManager;
};

#endif // WAREHOUSESYSTEMADDCUSTOMERDIALOG_H
