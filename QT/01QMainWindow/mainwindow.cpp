#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(600, 400);
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    QAction *newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    QToolBar *toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolbar->setFloatable(false);
    toolbar->setMovable(false);
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addAction(openAction);
    QPushButton *btn = new QPushButton("aaa", this);
    toolbar->addWidget(btn);

    QStatusBar *stbar = statusBar();
    setStatusBar(stbar);
    QLabel *label1 = new QLabel("left", this);
    stbar->addWidget(label1);
    QLabel *label2 = new QLabel("right", this);
    stbar->addPermanentWidget(label2);

    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

    QDockWidget *dock = new QDockWidget("Dock", this);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}
