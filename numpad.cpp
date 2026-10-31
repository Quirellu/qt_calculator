
#include "numpad.h"

Numpad::Numpad(QWidget* parent) : QWidget(parent)
{
    gridLayout = new QGridLayout(this);
    buttonGroup = new QButtonGroup(this);

    for (int i = 0; i < inputs.size(); i++)
    {
        auto *button = new QPushButton(this->inputs[i]);
        buttonGroup->addButton(button, i);

        gridLayout->addWidget(button, i/col_count, i%col_count);
    }

    connect(buttonGroup, &QButtonGroup::buttonPressed, this, &Numpad::processButtonText);

}

void Numpad::processButtonText(const QAbstractButton *button)
{
    if (button->text() == "=")
    {
        emit executeCalculation();
    }else
    {
        emit sendText(button->text());
    }

}
