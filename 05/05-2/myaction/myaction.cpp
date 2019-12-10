#include "myaction.h"
#include "QLineEdit"
#include "QSplitter"
#include "QLabel"
MyAction::MyAction(QObject * parent):
    QWidgetAction (parent)
{
    //创建行编辑器
    lineEdit = new QLineEdit;
    //将行编辑器的按下回车键信号与发送文本槽关联
    connect(lineEdit, &QLineEdit::returnPressed, this, &MyAction::sendText);
}

QWidget *MyAction::createWidget(QWidget *parent)
{
    //这里使用inherits()函数判断父部件是否是菜单或者工具栏
    if(parent->inherits("QMenu") || parent->inherits("QToolBar")){
        QSplitter *splitter = new QSplitter(parent);
        QLabel *label = new QLabel;
        label->setText(tr("插入文本："));
        splitter->addWidget(label);
        splitter->addWidget(lineEdit);
        return splitter;
    }
    return 0;
}

void MyAction::sendText()
{
    //发射信号，将行编辑中的内容发射出去
    emit getText(lineEdit->text());
    //清空行编辑器中的内容
    lineEdit->clear();
}

