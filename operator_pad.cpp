
#include "operator_pad.h"

#include <iostream>

OperatorPad::OperatorPad(QWidget* parent) : QWidget(parent)
{
    gridLayout = new QGridLayout(this);
    buttonGroup = new QButtonGroup(this);

    for (int i = 0; i < inputs.size(); i++)
    {
        auto *button = new QPushButton(this->inputs[i]);
        buttonGroup->addButton(button, i);

        gridLayout->addWidget(button, i%row_count, i/row_count);
    }

    connect(buttonGroup, &QButtonGroup::buttonPressed, this, &OperatorPad::processButtonText);
}

void OperatorPad::processButtonText(const QAbstractButton *button)
{   if (button->text() == "CLR")
    {
        emit sendResetSignal();
    }else
    {
        emit sendText(button->text());
    }
}
