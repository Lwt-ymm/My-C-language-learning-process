#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void timerEvent(QTimerEvent *event);
private:
    Ui::Widget *ui;
    int id1;
    int id2;

    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // WIDGET_H
