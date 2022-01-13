#include "gui.h"
#include <QDebug>

Gui::Gui(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    m_timer = new QTimer();
    m_status = false;
    // Verbinde: Quelle (Timeout aus Timer) -> Ziel (Toggle-Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);
}

void Gui::on_startButton_clicked()
{
    m_timer->start(1000/speedSlider->value());
}

void Gui::toggle()
{
    //qDebug() << "toggle";
    m_status = !m_status;
    blinkLabel->setNum(m_status);
}

void Gui::on_speedSlider_valueChanged(int value)
{
    if(m_timer->isActive())
         m_timer->start(1000/value);     // slider 1....10 -> 1000....100 ms period
}
