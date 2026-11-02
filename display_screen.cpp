#include "display_screen.h"

DisplayScreen::DisplayScreen(QWidget* parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    textDisplay = new QLineEdit(this);

    textDisplay->setText("0");
    textDisplay->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    textDisplay->setReadOnly(true);
    textDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(textDisplay);

    isScreenOverwritable = true;
}

void DisplayScreen::updateScreen(const QString& output)
{
    textDisplay->setText(output);
}

void DisplayScreen::appendScreen(const QString& output)
{
    QString current = textDisplay->text();

    bool isDouble;
    output.toDouble(&isDouble);

    if (isScreenOverwritable && isDouble)
    {
        current = output;
        isScreenOverwritable = false;
    }
    else
    {
        current.append(output);
    }

    textDisplay->setText(current);
}

void DisplayScreen::resetScreen()
{
    textDisplay->clear();
    textDisplay->setText("0");
    isScreenOverwritable = true;
}

void DisplayScreen::backspace()
{
    textDisplay->backspace();
}

std::string DisplayScreen::getTextDisplay() const
{
    return textDisplay->text().toStdString();
}

void DisplayScreen::set_is_screen_overwritable(const bool is_screen_overwritable)
{
    isScreenOverwritable = is_screen_overwritable;
}

