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
}

void DisplayScreen::updateScreen(const QString& output)
{
    textDisplay->setText(output);
}

void DisplayScreen::appendScreen(const QString& output)
{
    QString current = textDisplay->text();

    if (current == "0")
    {
        if (output == "00")
            return;

        current = output;
    }
    else
    {
        current.append(output);
    }

    textDisplay->setText(current);
}

