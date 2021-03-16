#include "WarehouseSystemAddProductDialog.h"
#include "ui_WarehouseSystemAddProductDialog.h"

#include "WarehouseSystemDataManager.h"

WarehouseSystemAddProductDialog::WarehouseSystemAddProductDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::WarehouseSystemAddProductDialog),
    m_dataManager(new WarehouseSystemDataManager())
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemAddProductDialog::~WarehouseSystemAddProductDialog()
{
    delete m_ui;
    delete m_dataManager;
}

void WarehouseSystemAddProductDialog::prepareConnections()
{
    connect(m_ui->leName, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(checkInputSlot()));
    connect(m_ui->dspCount, SIGNAL(valueChanged(double)), this, SLOT(checkInputSlot()));
    connect(m_ui->dspPurchasePrice, SIGNAL(valueChanged(double)), this, SLOT(checkInputSlot()));

    connect(m_ui->pbSave, SIGNAL(clicked()), this, SLOT(addNewProductSlot()));

    connect(m_ui->pbClose, SIGNAL(clicked()), this, SLOT(close()));
}

void WarehouseSystemAddProductDialog::prepareUi()
{
    m_ui->pbSave->setEnabled(false);

    foreach (auto unitOfMeasure, m_dataManager->unitsOfMeasureProductList())
    {
        m_ui->cbUnitOfMeasure->addItem(unitOfMeasure);
    }
}

void WarehouseSystemAddProductDialog::checkInputSlot()
{
    QObject *senderObject = sender();

    if (senderObject == m_ui->leName)
    {
        if (m_ui->leName->text().isEmpty())
        {
            m_ui->lCheckName->setText("Поле заполнено некорректно");
            m_ui->lCheckName->setStyleSheet("color: red;");
        }
        else
        {
            m_ui->lCheckName->setText(QString());
        }
    }
    else if (senderObject == m_ui->dspCount)
    {
        if (m_ui->dspCount->value() == 0.00)
        {
            m_ui->lCheckCount->setText("Поле заполнено некорректно");
            m_ui->lCheckCount->setStyleSheet("color: red;");
        }
        else
        {
            m_ui->lCheckCount->setText(QString());
        }
    }
    else if (senderObject == m_ui->dspPurchasePrice)
    {
        if (m_ui->dspPurchasePrice->value() == 0.00)
        {
            m_ui->lCheckPurchasePrice->setText("Поле заполнено некорректно");
            m_ui->lCheckPurchasePrice->setStyleSheet("color: red;");
        }
        else
        {
            m_ui->lCheckPurchasePrice->setText(QString());
        }
    }

    if (!m_ui->leName->text().isEmpty() &&
            m_ui->dspCount->value() != 0.00 &&
            m_ui->dspPurchasePrice->value() != 0.00)
    {
        m_ui->pbSave->setEnabled(true);
    }
    else
    {
        m_ui->pbSave->setEnabled(false);
    }
}

void WarehouseSystemAddProductDialog::addNewProductSlot()
{
    m_dataManager->addProduct(m_ui->leName->text(),
                              m_ui->dspCount->value(),
                              m_ui->cbUnitOfMeasure->currentIndex(),
                              m_ui->dspPurchasePrice->value());

    emit addProductToDBSignal();
}
