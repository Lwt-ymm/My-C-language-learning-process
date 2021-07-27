#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1 = startTimer(1000);

    id2 = startTimer(2000);

    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        timer->stop();
    });

    ui->label->installEventFilter(this);
}

void Widget::timerEvent(QTimerEvent *event) {

    if(event->timerId() == id1) {
        static int num1 = 1;
        ui->label_2->setText(QString::number(num1++));
    }
    if(event->timerId() == id2) {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}

bool Widget::eventFilter(QObject *watched, QEvent *event) {
    if(watched == ui->label) {
        if(event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *ev = static_cast<QMouseEvent *>(event);
            QString qs = QString("EventFilter::鼠标按下了x=%1 y=%2").arg(ev->x()).arg(ev->y());
            qDebug() << qs;
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}


Widget::~Widget()
{
    delete ui;
}
