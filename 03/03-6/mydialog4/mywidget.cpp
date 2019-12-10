#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "mydialog.h"
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->showChildButton, &QPushButton::clicked, this, &MyWidget::showChildDialog);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    // 模态/非模态窗口
    dialog->setModal(true);
    dialog->show();
}

void MyWidget::on_pushButton_clicked()
{
    close();

    MyDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
        show();
}
