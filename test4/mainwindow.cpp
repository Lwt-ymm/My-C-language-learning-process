#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew->setIcon(QIcon("F:/WG/WeGame/WeGameApps/WeGameApps/英雄联盟/WeGameLauncher/game/game.ico"));

    //使用添加Qt资源
    //ui->actionnew->setIcon(QIcon(":/pictures/0427dc67f7578f516a8e0a93525546d4_720w.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
