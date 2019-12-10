#include "mylineedit.h"
#include <QKeyEvent>
#include <QLineEdit>
#include <QDebug>
MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug()<< tr("MyLineEdit的event()函数");
    return QLineEdit::event(event); //执行QLineEdit类的event()函数的默认操作
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< tr("MyLineEdit键盘按下事件……");
    QLineEdit::keyPressEvent(event);            //执行QLineEdit类的默认事件处理，行编辑器能够输入字符
    event->ignore();                            //忽略该事件
}

