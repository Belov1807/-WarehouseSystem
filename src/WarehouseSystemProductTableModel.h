#ifndef WAREHOUSESYSTEMPRODUCTTABLEMODEL_H
#define WAREHOUSESYSTEMPRODUCTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVariant>

class WarehouseSystemDataManager;

/*!
 * \brief Класс табличной модели продукции.
 */
class WarehouseSystemProductTableModel  : public QAbstractTableModel
{
public:
    /*!
     * \brief Констуктор табличной модели.
     */
    WarehouseSystemProductTableModel();
    /*!
     * \brief Деструктор.
     */
    ~WarehouseSystemProductTableModel();

    /*!
     * \brief Возвращает количество строк.
     * \param _parent - индекс модели.
     * \return Количество строк.
     */
    int rowCount(const QModelIndex &_parent = QModelIndex()) const;
    /*!
     * \brief Возвращает количество столбцов.
     * \param _parent - индекс модели.
     * \return Количество столбцов.
     */
    int columnCount(const QModelIndex &_parent = QModelIndex()) const;

    /*!
     * \brief Возвращает значение элемента.
     * \param _index - индекс элемента.
     * \param _role - роль элемента.
     * \return Значение элемента.
     */
    QVariant data(const QModelIndex &_index, int _role) const;
    /*!
     * \brief Возвращает название колонки.
     * \param _section - номер колонки.
     * \param _orientation - ориентация.
     * \param _role - роль.
     * \return Название колонки.
     */
    QVariant headerData(int _section, Qt::Orientation _orientation, int _role = Qt::DisplayRole) const;

private:
    /*!
     * \brief Колонки модели.
     */
    enum TableColumn {
                        nameColumn,                 ///< Колонка имени.
                        countColumn,                ///< Колонка количества.
                        typeColumn,                 ///< Колонка еденицы измерения.
                        purchasePriceColumn,        ///< Колонка цены закупки.

                        columnsCount                ///< Количество колонок.
    };

    /*!
     * \brief Менеджер данных.
     */
    WarehouseSystemDataManager *m_dataManager;
};

#endif // WAREHOUSESYSTEMPRODUCTTABLEMODEL_H
