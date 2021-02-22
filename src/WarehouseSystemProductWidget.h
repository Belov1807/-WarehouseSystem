#ifndef WAREHOUSESYSTEMPRODUCTWIDGET_H
#define WAREHOUSESYSTEMPRODUCTWIDGET_H

#include <QWidget>

class WarehouseSystemProductTableModel;

namespace Ui {
class WarehouseSystemProductWidget;
}

/*!
 * \brief Класс виджета продукции.
 */
class WarehouseSystemProduct;

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
    Ui::WarehouseSystemProductWidget *m_ui;
};

#endif // WAREHOUSESYSTEMPRODUCTWIDGET_H
