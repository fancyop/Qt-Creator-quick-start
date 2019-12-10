#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QWheelEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);     //为编辑器部件在窗口上安装事件过滤器
    ui->spinBox->installEventFilter(this);

    //QKeyEvent对象在栈上创建
    QKeyEvent myEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier);
    //qApp是QApplication对象的全局指针，每一个应用程序只能使用一个QApplication对象

    //发送事件给spinBox,经过下6行代码，部件的初始值变为了6
    qApp->sendEvent(ui->spinBox,&myEvent);      //发送键盘事件到spinBox部件
    qApp->sendEvent(ui->spinBox,&myEvent);      //发送键盘事件到spinBox部件
    qApp->sendEvent(ui->spinBox,&myEvent);      //发送键盘事件到spinBox部件
    qApp->sendEvent(ui->spinBox,&myEvent);      //发送键盘事件到spinBox部件
    qApp->sendEvent(ui->spinBox,&myEvent);      //发送键盘事件到spinBox部件
    qApp->sendEvent(ui->spinBox,&myEvent);      //发送键盘事件到spinBox部件

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event)   //事件过滤器
{
    if(obj == ui->textEdit){                    //判断部件
        if(event->type() == QEvent::Wheel){     //判断事件
            //将event强制转换为发生的事件的类型
            QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);
            if(wheelEvent->delta()>0) ui->textEdit->zoomIn();//滚轮放大缩小字体
            else ui->textEdit->zoomOut();
            return true;
        }else{
            return false;
        }

    }else if(obj == ui->spinBox){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if(keyEvent->key() == Qt::Key_Space){           //使用空格来使数值设置为0
                ui->spinBox->setValue(0);
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else
        return QWidget::eventFilter(obj,event);
}
