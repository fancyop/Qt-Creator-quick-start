#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLineEdit>
#include <QDebug>
#include <QCompleter>
MyWidget::MyWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // lineEdit_3
//    //验证器，对输入数据进行约束整形数据：100-999
//    QValidator * validator = new QIntValidator(100, 999, this);
//    ui->lineEdit_3->setValidator(validator);

    //使用正则表达式来约束：输入"-"或者不输入，然后输入1-3个数字
    QRegExp rx("-?\\d{1,3}");
    QValidator * validator = new QRegExpValidator(rx, this);
    ui->lineEdit_3->setValidator(validator);

    //lineEdit_4
    QStringList wordList;
    wordList << "Qt" << "Qt Creator" << tr("你好");
    QCompleter * completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_4->setCompleter(completer);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_lineEdit_2_returnPressed()
{
    //必须要输入的字符没有输入完成，回车键是没有作用的
    ui->lineEdit_3->setFocus();
    qDebug()<< ui->lineEdit_2->text();
    qDebug()<< ui->lineEdit_2->displayText();
}
