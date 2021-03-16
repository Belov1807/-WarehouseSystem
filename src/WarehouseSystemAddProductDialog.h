#ifndef WAREHOUSESYSTEMADDPRODUCTDIALOG_H
#define WAREHOUSESYSTEMADDPRODUCTDIALOG_H

#include <QDialog>

class WarehouseSystemDataManager;

namespace Ui {
class WarehouseSystemAddProductDialog;
}

/*!
 * \brief Класс диалога добавления новой продукции.
 */
class WarehouseSystemAddProductDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit WarehouseSystemAddProductDialog(QWidget *parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemAddProductDialog();

private slots:
    /*!
     * \brief Слот проверки введенных данных.
     */
    void checkInputSlot();

    /*!
     * \brief Слот добавления новой продукции.
     */
    void addNewProductSlot();

signals:
    /*!
     * \brief Сигнал добавления новой продукции в базу данных.
     */
    void addProductToDBSignal();

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
    Ui::WarehouseSystemAddProductDialog *m_ui;

    /*!
     * \brief Менеджер данных.
     */
    WarehouseSystemDataManager *m_dataManager;
};

#endif // WAREHOUSESYSTEMADDPRODUCTDIALOG_H
