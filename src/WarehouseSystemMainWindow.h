#ifndef WAREHOUSESYSTEMMAINWINDOW_H
#define WAREHOUSESYSTEMMAINWINDOW_H

#include <QMainWindow>

class WarehouseSystemInfoOfCompanyWidget;
class WarehouseSystemCustomersWidget;
class WarehouseSystemProductWidget;
class WarehouseSystemArrangeOrderWidget;

QT_BEGIN_NAMESPACE
namespace Ui {
class WarehouseSystemMainWindow;
}
QT_END_NAMESPACE

/*!
 * \brief Класс главного окна приложения.
 */
class WarehouseSystemMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    WarehouseSystemMainWindow(QWidget *_parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemMainWindow();

private slots:
    /*!
     * \brief Слот открытия виджета "Информация о компании".
     */
    void infoOfCompanyWidgetSlot();
    /*!
     * \brief Слот открытия виджета "Покупатели".
     */
    void customersSlot();
    /*!
     * \brief Слот открытия виджета "Продукция".
     */
    void productsSlot();
    /*!
     * \brief Слот открытия виджета "Оформление заказа".
     */
    void arrangeOrderWidgetSlot();
    void closeWindowSlot();

private:
    /*!
     * \brief Подготавливает соеденения.
     */
    void prepareConnections();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemMainWindow *m_ui;

    /*!
     * \brief Виджет информации о компании.
     */
    WarehouseSystemInfoOfCompanyWidget *m_infoOfCompanyWidget;
    /*!
     * \brief Виджет "Покупатели".
     */
    WarehouseSystemCustomersWidget *m_customersWidget;
    /*!
     * \brief Виджет "Продукция".
     */
    WarehouseSystemProductWidget *m_productsWidget;
    /*!
     * \brief Виджет "Оформление заказа".
     */
    WarehouseSystemArrangeOrderWidget *m_arrangeOrderWidget;
};
#endif // WAREHOUSESYSTEMMAINWINDOW_H
