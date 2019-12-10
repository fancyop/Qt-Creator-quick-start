#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()  //确定按钮
{
    int value = ui->spinBox->value();   //获取输入的数值
    emit dlgReturn(value);              //发射信号
    close();                            //关闭对话框
}
