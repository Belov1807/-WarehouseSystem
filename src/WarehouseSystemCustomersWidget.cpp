#include "WarehouseSystemCustomersWidget.h"
#include "ui_WarehouseSystemCustomersWidget.h"

#include "WarehouseSystemCustomersTableModel.h"

WarehouseSystemCustomersWidget::WarehouseSystemCustomersWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::WarehouseSystemCustomersWidget)
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemCustomersWidget::~WarehouseSystemCustomersWidget()
{
    delete m_ui;
}

void WarehouseSystemCustomersWidget::prepareConnections()
{
    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemCustomersWidget::prepareUi()
{
    WarehouseSystemCustomersTableModel *model = new WarehouseSystemCustomersTableModel();

    m_ui->tvCustomers->setModel(model);
}
