
#include "calculator.h"

#include <iostream>

Calculator::Calculator(QWidget* parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    keyboard_layout = new QHBoxLayout(this);

    display = new DisplayScreen(this);
    numpad = new Numpad(this);
    operatorPad = new OperatorPad(this);

    display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    keyboard_layout->addWidget(numpad);
    keyboard_layout->addWidget(operatorPad);

    layout->addWidget(display);
    layout->addLayout(keyboard_layout);

    layout->setStretch(0, 2);
    layout->setStretch(1, 3);

    QObject::connect(numpad, &Numpad::sendText, display, &DisplayScreen::appendScreen);
    QObject::connect(operatorPad, &OperatorPad::sendText, display, &DisplayScreen::appendScreen);
    QObject::connect(operatorPad, &OperatorPad::sendResetSignal, display, &DisplayScreen::resetScreen);
    QObject::connect(operatorPad, &OperatorPad::sendBackspaceSignal, display, &DisplayScreen::backspace);
    QObject::connect(numpad, &Numpad::executeCalculation, this, &Calculator::calculateAndUpdateScreen);

}

void Calculator::calculateAndUpdateScreen()
{
    try
    {
    const auto answer = std::to_string(this->engine.calculate(display->getTextDisplay()));
        this->display->updateScreen(QString::fromStdString(answer));
    }catch (const std::runtime_error &e)
    {
        this->display->updateScreen(QString::fromStdString(e.what()));
    }

}


