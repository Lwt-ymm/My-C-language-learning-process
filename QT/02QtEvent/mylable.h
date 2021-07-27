#ifndef MYLABLE_H
#define MYLABLE_H

#include <QLabel>

class MyLable : public QLabel
{
    Q_OBJECT
public:
    explicit MyLable(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    bool event(QEvent *e);
signals:

public slots:
};

#endif // MYLABLE_H
