#ifndef QT_CALCULATOR_DISPLAY_SCREEN_H
#define QT_CALCULATOR_DISPLAY_SCREEN_H

#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

class DisplayScreen : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayScreen(QWidget *parent = nullptr);

public slots:
    void updateScreen(const QString& output);
    void appendScreen(const QString& output);
    void resetScreen();
    void backspace();

    [[nodiscard]] std::string getTextDisplay() const;

private:
    QLineEdit* textDisplay;
    QVBoxLayout* layout;
};

#endif //QT_CALCULATOR_DISPLAY_SCREEN_H
