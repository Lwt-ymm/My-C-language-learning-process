#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew, &QAction::triggered, [=](){
//        QDialog dlg(this);
//        dlg.resize(200, 60);
//        dlg.exec();
//        QDialog *dlg = new QDialog(this);
//        dlg->resize(200, 60);
//        dlg->show();
//        dlg->setAttribute(Qt::WA_DeleteOnClose);
//        QMessageBox::critical(this, "critical", "错误");
//        QMessageBox::information(this, "information", "提示");
//        if(QMessageBox::Save == QMessageBox::question(this, "question", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel)) qDebug() << "保存";
//        else qDebug() << "取消";
//        QMessageBox::warning(this, "warning", "警告");
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue() << endl;
//        QString str = QFileDialog::getOpenFileName(this, "打开文件", "C:/Users/96170/Desktop", "*.txt");
//        qDebug() << str << endl;
//        bool ok;
//        QFont font = QFontDialog::getFont(&ok, QFont("华文彩云", 26));
//        qDebug() << "字体：" << font.family() << "字号：" << font.pointSize() << "加粗：" << font.bold() << "倾斜：" << font.italic() << endl;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
