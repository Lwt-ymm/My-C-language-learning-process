#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QString>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton("open", this);
    setWindowTitle("第一个窗口");
    resize(600, 400);
    QWidget *sw = new QWidget;
    sw->setWindowTitle("第二个窗口");
    connect(btn, &QPushButton::clicked, [=](){
        if(btn->text() == "open") {
            sw->show();
            btn->setText("close");
        }
        else{
            sw->close();
            btn->setText("open");
        }
    });

}

Widget::~Widget()
{

}
