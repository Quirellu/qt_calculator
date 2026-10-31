
#ifndef QT_CALCULATOR_OPERATOR_PAD_H
#define QT_CALCULATOR_OPERATOR_PAD_H

#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QWidget>



class OperatorPad : public QWidget
{
    Q_OBJECT
public:
    explicit OperatorPad(QWidget* parent = nullptr);

private:
    QGridLayout* gridLayout;
    QButtonGroup* buttonGroup;

    uint8_t row_count = 4;
    uint8_t col_count = 1;

    const std::array<QString, 4> inputs
    {
        "/", "x", "-", "+"
    };

signals:
    void sendText(const QString& output);


private slots:
    void processButtonText(const QAbstractButton *button);
};


#endif //QT_CALCULATOR_OPERATOR_PAD_H
