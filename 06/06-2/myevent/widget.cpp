#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>
#include "mylineedit.h"

#include <QPainter>
#include <QLabel>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(100,100,1000,600);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(450,20);
    lineEdit->installEventFilter(this);

    //在标签内显示图片：事件传递顺序示意图
    QLabel *label = new QLabel(this);
    QPixmap pix("../myevent/image.png");
    label->setPixmap(pix);
    label->resize(pix.size());
    label->move(20,50);
    label->setAttribute(Qt::WA_DeleteOnClose);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event)   //在Widget上为lineEdit安装事件过滤器
{
    if(obj == lineEdit){
        if(event->type() == QEvent::KeyPress){
            qDebug()<< tr("Widget的事件过滤器");
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< tr("Widget键盘按下事件");
//    event->ignore();                    //忽略该事件
}
