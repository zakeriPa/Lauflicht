#include "gui.h"
#include <QDebug>

Gui::Gui(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    m_timer = new QTimer();
    // Verbinde: Quelle (Timeout aus Timer) -> Ziel (Toggle-Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);
}

void Gui::on_startButton_clicked()
{
    m_timer->start(1000);
}

void Gui::toggle()
{
    qDebug() << "toggle";
}


//Graphic:
// Button 1 = Start Button / Name = Start / Window Title = Blink
// Label 1 = Blink Label / Name = 0 / Alignment ... Horizontal = Senter
