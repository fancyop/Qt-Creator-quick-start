#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList <QString>list;
    list << "A" << "B" << "C" << "D";
    QList <QString>::iterator i;        //使用读写迭代器
    qDebug() << "the forward is: ";
    for(i = list.begin(); i != list.end(); ++i){
        *i = (*i).toLower();            //使用QString的toLower()函数转换为小写
        qDebug() << *i;                 //结果为a,b,c,d
    }
    qDebug() <<"the backward is:";
    while (i != list.begin()) {
        --i;
        qDebug() << *i;                 //结果为d,c,b,a
    }
    QList <QString>::const_iterator j;  //使用只读迭代器
    qDebug()<<"the forwards is:";
    for(j=list.constBegin(); j!=list.constEnd(); ++j){
        qDebug()<< *j;
    }
    return a.exec();
}
