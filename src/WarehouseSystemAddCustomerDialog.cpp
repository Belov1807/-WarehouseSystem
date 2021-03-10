#include "WarehouseSystemAddCustomerDialog.h"
#include "ui_WarehouseSystemAddCustomerDialog.h"

WarehouseSystemAddCustomerDialog::WarehouseSystemAddCustomerDialog(QWidget *_parent) :
    QDialog(_parent),
    m_ui(new Ui::WarehouseSystemAddCustomerDialog)
{
    m_ui->setupUi(this);

    prepareConnections();
    prepareUi();
}

WarehouseSystemAddCustomerDialog::~WarehouseSystemAddCustomerDialog()
{
    delete m_ui;
}

void WarehouseSystemAddCustomerDialog::prepareConnections()
{
    connect(m_ui->lePhone, SIGNAL(textEdited(const QString &)), this, SLOT(changeInputMaskSlot()));

    connect(m_ui->leName, SIGNAL(editingFinished()), this, SLOT(checkInputSlot()));
    connect(m_ui->leINN, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(checkInputSlot()));
    connect(m_ui->lePhone, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(checkInputSlot()));
    connect(m_ui->leAddress, SIGNAL(editingFinished()), this, SLOT(checkInputSlot()));
}

void WarehouseSystemAddCustomerDialog::prepareUi()
{
    m_ui->leINN->setInputMask("DDDDDDDDDD;_");

    m_ui->lePhone->setInputMask("+7(DDDdd)DDDDD;_");
}

void WarehouseSystemAddCustomerDialog::changeInputMaskSlot()
{
    int phoneTextSize = m_ui->lePhone->text().count();
    if (phoneTextSize < 5)
    {
        m_ui->lePhone->setInputMask("+7(DDDdd)DDDDD;_");
    }
    else if ((phoneTextSize == 8 ||
              phoneTextSize == 9))
    {
        QString displayText = m_ui->lePhone->displayText();

        if (displayText.contains("_)") &&
                !displayText.contains(")_"))
        {
            int n = 8;

            for (int i = 6; i < n; i ++)
            {
                QString phone = m_ui->lePhone->text();

                if (phone.at(i) == ')')
                {
                    QString inputMask = m_ui->lePhone->inputMask();

                    int rearrangedSymbolsCount = n - i;
                    inputMask.remove(i, rearrangedSymbolsCount);

                    int cursorPosition = m_ui->lePhone->cursorPosition();

                    for (int j = 0; j < rearrangedSymbolsCount; j++)
                    {
                        inputMask.insert(cursorPosition, "D");
                    }
                    m_ui->lePhone->setInputMask(inputMask);

                    int newCursorPosition = cursorPosition - rearrangedSymbolsCount;
                    m_ui->lePhone->setCursorPosition(newCursorPosition);
                }
            }
        }
    }
}

void WarehouseSystemAddCustomerDialog::checkInputSlot()
{
    QString objectName = sender()->objectName();

    QLineEdit *lineEdit = findChild<QLineEdit *>(objectName);
    QLabel *checkLabel = findChild<QLabel *>("lCheck" + objectName.remove(0,2));

    if ((lineEdit->inputMask().isNull() &&
         lineEdit->text().isEmpty()) ||
            (!lineEdit->inputMask().isNull() &&
             lineEdit->text().count() != lineEdit->displayText().count()))
    {
        checkLabel->setText("Поле заполнено некорректно");
        checkLabel->setStyleSheet("color: red;");
    }
    else
    {
        checkLabel->setText("QString()");
    }
}
