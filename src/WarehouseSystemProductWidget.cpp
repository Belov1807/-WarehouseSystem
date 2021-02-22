#include "WarehouseSystemProductWidget.h"
#include "ui_WarehouseSystemProductWidget.h"

#include "WarehouseSystemProductTableModel.h"
#include "WarehouseSystemProduct.h"

WarehouseSystemProductWidget::WarehouseSystemProductWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WarehouseSystemProductWidget)
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemProductWidget::~WarehouseSystemProductWidget()
{
    delete m_ui;
}

void WarehouseSystemProductWidget::prepareConnections()
{
    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemProductWidget::prepareUi()
{
    WarehouseSystemProductTableModel *model = new WarehouseSystemProductTableModel();

    m_ui->tvProducts->setModel(model);
}
