#ifndef WAREHOUSESYSTEMPRODUCTWIDGET_H
#define WAREHOUSESYSTEMPRODUCTWIDGET_H

#include <QWidget>

class WarehouseSystemProductTableModel;
class WarehouseSystemAddProductDialog;

namespace Ui {
class WarehouseSystemProductWidget;
}

/*!
 * \brief Класс виджета продукции.
 */
class WarehouseSystemProductWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit WarehouseSystemProductWidget(QWidget *parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemProductWidget();

signals:
    /*!
     * \brief Сигнал закрытия виджета.
     * \param event - событие закрытия.
     */
    void closeEvent(QCloseEvent *event = nullptr) override;


private slots:
    /*!
     * \brief Слот открытия диалога добавления новой продукции.
     */
    void addProductDialogSlot();
    /*!
     * \brief Слот обновления табличной модели.
     */
    void updateTableSlot();
    /*!
     * \brief Слот удаления продукции.
     */
    void removeProductSlot();
    /*!
     * \brief Слот установления активности кнопки удалить продукцию.
     */
    void setEnabledPbRemoveProductSlot();
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

    /*!
     * \brief Устанавливает табличную модель.
     */
    void setTable();

    /*!
    * \brief Графический интерфейс.
    */
    Ui::WarehouseSystemProductWidget *m_ui;

    /*!
     * \brief Табличная модель.
     */
    WarehouseSystemProductTableModel *m_model;

    /*!
     * \brief Диалог добавления новой продукции.
     */
    WarehouseSystemAddProductDialog *m_addProductDialog;
};

#endif // WAREHOUSESYSTEMPRODUCTWIDGET_H
