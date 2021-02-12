#ifndef WAREHOUSESYSTEMMAINWINDOW_H
#define WAREHOUSESYSTEMMAINWINDOW_H

#include <QMainWindow>

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
     * \param parent - родительский виджет.
     */
    WarehouseSystemMainWindow(QWidget *parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemMainWindow();

private:
    /*!
     * \brief Графический интерфейс.
     */
    Ui::WarehouseSystemMainWindow *m_ui;
};
#endif // WAREHOUSESYSTEMMAINWINDOW_H
