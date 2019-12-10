#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList <QString> list;
    list <<"aa" <<"bb" <<"cc";              //插入项目
    if(list[1] == "bb") list[1] = "ab";
    list.replace(2,"bc");                   //将"cc"换位"bc"
    qDebug()<< "the list is: ";             //输出整个列表
    for(int i=0; i<list.size(); i++){
        qDebug()<< list.at(i);              //现在列表为aa ab bc
    }
    list.append("dd");                      //在列表尾部添加
    list.prepend("mm");                     //在列表头部添加
    //0  1  2  3  4
    //mm aa ab bc dd
    QString str = list.takeAt(2);           //从列表中删除第3个项目，并获取它
    qDebug()<< "at(2) item is: " << str;    //str为ab
    qDebug()<< "the list is: ";
    for(int i=0; i<list.size(); ++i){
        qDebug()<< list.at(i);
    }                                       //0  1  2  3  4
    list.insert(2, "mm");                   //mm aa mm bc dd
    list.swap(1, 3);                        //mm bc mm aa dd
    qDebug()<< "the list is: ";
    for(int i=0; i<list.size(); ++i){
        qDebug()<< list.at(i);
    }
    qDebug()<<"contains 'mm'?" << list.contains("mm");
    qDebug()<<"the 'mm' count: " << list.count("mm");
    qDebug()<<"the first 'mm' index: " << list.indexOf("mm");
    qDebug()<<"the second 'mm' index" << list.indexOf("mm", 1);

    return a.exec();
}
