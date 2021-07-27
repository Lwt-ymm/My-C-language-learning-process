#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionnew->setIcon(QIcon(":/bizhi/res/QQ截图20210124104130.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
