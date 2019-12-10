#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFocus();             //是主界面获得焦点

    keyUp = false;          //初始化变量
    keyLeft = false;
    move = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)                //按键按下事件
{
    if(event->key() == Qt::Key_Up){                         //如果是向上方向键
        if(event->isAutoRepeat())   return;                 //按键重复时不做处理
        keyUp = true;                                       //标记向上方向键已经按下
    }
    else if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat())   return;
        keyLeft = true;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)              //按键释放事件
{
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat())   return;             //按键重复时不做处理
        keyUp = false;                                  //释放按键后将标志设置为false
        if(move){                                       //如果已经完成了移动
            move = false;                               //设置标志位false
            return;
        }
        if(keyLeft){
            ui->pushButton->move(30,80);
            move = true;
        }else{
            ui->pushButton->move(120,80);
        }
    }
    else if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat())   return;
        keyLeft = false;
        if(move){
            move = false;
            return;
        }
        if(keyUp){
            ui->pushButton->move(30,80);
            move = true;
        }else{
            ui->pushButton->move(30,120);
        }
    }
    else if(event->key() == Qt::Key_Down){
        ui->pushButton->move(120,120);
    }
}
