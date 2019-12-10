#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
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

    //模态和非模态控制
    dialog->setModal(true);

    dialog->show();
}
