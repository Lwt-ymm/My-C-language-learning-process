#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_get, &QPushButton::clicked,[=](){
        qDebug() << ui->widget->getval();
    });
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->widget->setval(50);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
