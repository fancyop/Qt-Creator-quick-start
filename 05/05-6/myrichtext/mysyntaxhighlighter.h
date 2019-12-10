#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>


class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT            //使用QT中的signal和slot机制。
public:
    explicit MySyntaxHighlighter(QTextDocument *parent = nullptr);

protected:
    //编辑器中的文本改变时都会调用highlightBlock()函数来设置语法高亮
    void highlightBlock(const QString &text);
};

#endif // MYSYNTAXHIGHLIGHTER_H
