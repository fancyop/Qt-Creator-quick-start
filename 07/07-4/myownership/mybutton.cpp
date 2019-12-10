#include "mybutton.h"
#include <QDebug>
#include <QPushButton>
MyButton::MyButton(QWidget *parent):
    QPushButton (parent)
{

}

MyButton::~MyButton()
{
    qDebug()<< "delete button";     //MyButton对象销毁时输出调试信息
}
