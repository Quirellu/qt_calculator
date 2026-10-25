#ifndef QT_CALCULATOR_NUMPAD_H
#define QT_CALCULATOR_NUMPAD_H

#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QString>
#include <QWidget>
#include <array>

class Numpad : public QWidget
{
    Q_OBJECT

public:
    explicit Numpad(QWidget* parent = nullptr);

private:
    QGridLayout* gridLayout;
    QButtonGroup* buttonGroup;

    uint8_t row_count = 4;
    uint8_t col_count = 3;

    const std::array<QString, 12> inputs
    {
        "7", "8", "9",
        "4", "5", "6",
        "1", "2", "3",
        "0", "00", ".",
    };

signals:
    void sendText(const QString& output);

private slots:
    void processButtonText(const QAbstractButton *button);

};


#endif //QT_CALCULATOR_NUMPAD_H
