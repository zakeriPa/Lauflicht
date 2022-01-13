#ifndef GUI_H
#define GUI_H

#include <QTimer>
#include "ui_gui.h"

class Gui : public QMainWindow, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
    void on_startButton_clicked();

private:
    QTimer* m_timer;
    bool m_status;
    void toggle();
};

#endif // GUI_H
