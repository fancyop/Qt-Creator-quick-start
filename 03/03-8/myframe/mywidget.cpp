#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>
#include <QPalette>
#include <QtDebug>
#include <QDir>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // label
    QFont font;
    font.setFamily("黑体");
    font.setItalic(false);
    font.setBold(false);
    font.setPixelSize(16);

    ui->label->setFont(font);
    ui->label->setWordWrap(false);//关闭自动换行

    QString string = tr("标题太长，需要进行省略！");
    //截断、省略文本的作用
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 120);

    ui->label->setText(str);

    qDebug()<< QDir::currentPath();
    //label_2
    ui->label_2->setPixmap(QPixmap("./../myframe/icon.jpg"));

    //label_3
    QMovie *movie = new QMovie("./../myframe/test.gif");
    ui->label_3->setMovie(movie);
    movie->start();

    //lcdNumber
    ui->lcdNumber->display(10086.11);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    QPalette lcdpat = ui->lcdNumber->palette();
    lcdpat.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
    ui->lcdNumber->setPalette(lcdpat);


}

MyWidget::~MyWidget()
{
    delete ui;
}
