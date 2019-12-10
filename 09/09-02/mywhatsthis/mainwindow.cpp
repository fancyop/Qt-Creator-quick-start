#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWhatsThis>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *action = QWhatsThis::createAction(this);
    ui->mainToolBar->addAction(action);
}

MainWindow::~MainWindow()
{
    delete ui;
}
