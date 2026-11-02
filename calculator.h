
#ifndef QT_CALCULATOR_CALCULATOR_H
#define QT_CALCULATOR_CALCULATOR_H
#include "CalculationEngine.h"
#include "display_screen.h"
#include "numpad.h"
#include "operator_pad.h"

class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget* parent = nullptr);

private:
    CalculationEngine engine;
    DisplayScreen* display;
    Numpad* numpad;
    OperatorPad* operatorPad;
    QVBoxLayout* layout;
    QHBoxLayout* keyboard_layout;

    double previousAnswer;

    void calculateAndUpdateScreen();
};

#endif //QT_CALCULATOR_CALCULATOR_H
