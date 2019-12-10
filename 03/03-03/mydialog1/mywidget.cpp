#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //非模态窗口
    //方式2：因为定义的是变量，在函数执行完了会被自动释放，现象即一闪而逝
//    QDialog dialog(this);
//    dialog.show();
    //方式1：定义指向QDialog对象的指针变量
//    QDialog * dialog = new QDialog(this);
//    dialog->show();



    //模态窗口
    //方式1
//    QDialog dialog(this);
//    dialog.exec();
    //方式2
    QDialog *dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->show();
}

MyWidget::~MyWidget()
{
    delete ui;
}
