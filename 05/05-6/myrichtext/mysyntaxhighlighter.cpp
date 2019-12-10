#include "mysyntaxhighlighter.h"
#include <QDebug>
MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent):
    QSyntaxHighlighter (parent)
{

}

//编辑器中的文本改变时都会调用highlightBlock()函数来设置语法高亮
void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat myFormat;                       //字符格式
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::blue);
    QString pattern = "\\bchar\\b";                 //要匹配的字符，这里是“char”单词
    QRegExp expresssion(pattern);                   //创建正则表达式
    int index = text.indexOf(expresssion);          //从位置0开始匹配字符串
    qDebug()<< "index: " << index;
    //如果匹配成功，那么返回值为字符串的起始位置，它大于或等于0
    while (index >= 0) {
        int length = expresssion.matchedLength();   //要匹配字符串的长度
        setFormat(index, length, myFormat);         //对要匹配的字符串设置格式
        index = text.indexOf(expresssion, index + length);
        qDebug()<< "index: " << index;
    }
}
