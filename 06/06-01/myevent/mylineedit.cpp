#include "mylineedit.h"
#include <QKeyEvent>
#include <QLineEdit>
#include <QDebug>
MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< tr("MyLineEdit键盘按下事件……");
    QLineEdit::keyPressEvent(event);            //执行QLineEdit类的默认事件处理，行编辑器能够输入字符
    event->ignore();                            //忽略该事件
}

