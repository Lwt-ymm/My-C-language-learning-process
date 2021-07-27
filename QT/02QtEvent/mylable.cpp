#include "mylable.h"
#include <QDebug>
#include <QMouseEvent>

MyLable::MyLable(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);


}

void MyLable::enterEvent(QEvent *event) {
    qDebug() << "鼠标进入了";
}

void MyLable::leaveEvent(QEvent *event) {
    qDebug() << "鼠标离开了";
}

void MyLable::mousePressEvent(QMouseEvent *ev) {
    if(ev->button() == Qt::LeftButton) {
        QString qs = QString("鼠标按下了x=%1 y=%2").arg(ev->x()).arg(ev->y());
        qDebug() << qs;
    }
}

void MyLable::mouseReleaseEvent(QMouseEvent *ev) {
    QString qs = QString("鼠标释放了x=%1 y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << qs;
}

void MyLable::mouseMoveEvent(QMouseEvent *ev) {
     //if(ev->buttons() & Qt::LeftButton) {
        QString qs = QString("鼠标移动了x=%1 y=%2").arg(ev->x()).arg(ev->y());
        qDebug() << qs;
     //}
}

bool MyLable::event(QEvent *e) {
    if(e->type() == QEvent::MouseButtonPress) {
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString qs = QString("Event::鼠标按下了x=%1 y=%2").arg(ev->x()).arg(ev->y());
        qDebug() << qs;
        return true;
    }
    return QLabel::event(e);
}
