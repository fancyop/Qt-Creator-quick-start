#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //编辑操作
    qDebug() << QObject::tr("以下是编辑字符串操作：") << endl;
    QString str = "hello";
    qDebug() << QObject::tr("字符串大小：") << str.size();    //大小为5
    str[0] = QChar('H');        //"Hello
    qDebug() << QObject::tr("第一个字符：") << str[0];
    str.append("Qt");           //"HelloQt"
    str.replace(1,4,"i");       //"Hi   Qt"
    str.insert(2," my");        //"Hi myQt"
    qDebug() << QObject::tr("str为：") << str;    //"Hi myQt"
    str = str + "!!!";
    qDebug() << QObject::tr("str为：") << str;    //"Hi myQt!!!"
    str = " hi\r\n Qt! \n    ";
    qDebug() << QObject::tr("str为：") << str;    //"hi\r\n Qt! \r\n    "
    QString str1 = str.trimmed();   //除去字符串两端的空白字符= '\t', '\n', '\v', '\f', '\r', and ' '.
    qDebug() << QObject::tr("str1为：") << str1;  //"hi\r\n Qt!"
    QString str2 = str.simplified();//从开始和结束处删除空白，并用一个空格替换每个内部空白序列
    qDebug() << QObject::tr("str2为：") << str2;  //"hi Qt!"
    str = "hi,my,,Qt";
    //从字符串中有","的地方将其分为多个子字符串
    //QString::SkipEmptyParts表示跳过空的条目
    QStringList list = str.split(",",QString::SkipEmptyParts);
    qDebug() << QObject::tr("str拆分后为：") << list;
    str = list.join(" ");
    qDebug() << QObject::tr("list组合后为：") << str;
    qDebug() << QString().isNull();
    qDebug() << QString().isEmpty();
    qDebug() << QString("").isNull();
    qDebug() << QString("").isEmpty();

    //查询操作
    qDebug() << endl << QObject::tr("以下是在字符串中进行查询的操作：") << endl;
    str = "fancylinux";
    qDebug() << QObject::tr("字符串为：") << str;
    //执行下面一行代码后，结果为linux
    qDebug() << QObject::tr("包含右侧5个字符的子字符串：") << str.right(5);
    //执行下面一行代码后，结果为fancy
    qDebug() << QObject::tr("包含左侧5个字符的子字符串：") << str.left(5);
    //执行下面一行代码后，结果为ncy
    qDebug() << QObject::tr("包含第2个字符以后3个字符的字符串：") << str.mid(2,3);
    qDebug() << QObject::tr("'ncy'的位置：") << str.indexOf("ncy");
    qDebug() << QObject::tr("str的第0个字符：") << str.at(0);
    qDebug() << QObject::tr("str中'n'字符个个数：") << str.count('n');
    //执行下面一行代码后，结果为true
    qDebug() << QObject::tr("str是否以‘fan'开始？") << str.startsWith("fan");
    qDebug() << QObject::tr("str是否以‘linux'结尾？") << str.endsWith("linux");
    qDebug() << QObject::tr("str是否包含’lin‘字符串？") << str.contains("lin");
    QString temp = "hello";
    if(temp > str) qDebug() << temp;    //对应两个字符串的比较，可以使用">" "<="等操作
    else qDebug() << str;               //也可以使用compare()函数

    //转换操作
    qDebug() << endl << QObject::tr("以下是字符串的转换操作：") << endl;
    str = "100";
    qDebug() << QObject::tr("字符串转换为整数：") << str.toInt();
    int num = 45;
    qDebug() << QObject::tr("整数转换为字符串：") << QString::number(num);
    str = "FF";
    bool ok;
    int hex = str.toInt(&ok, 16);           //转换成功true，转换失败false
    qDebug() << "ok: " << ok << QObject::tr("转换为十六进制：") << hex;
    num = 26;
    qDebug() << QObject::tr("使用十六进制将整数转换为字符串：")
             << QString::number(num,16);    //结果为1a
    str = "123.456";
    qDebug() << QObject::tr("字符串转换为浮点型：") << str.toFloat(); //结果为123.456
    str = "abc";
    qDebug() << QObject::tr("转换为大写：") << str.toUpper();     //结果为ABC
    str = "QWER";
    qDebug() << QObject::tr("转换为小写：") << str.toLower();     //结果为abc
    int age = 3;
    QString name = "fancyop";
    //name代替%1，age代替%2
    str = QString("name is %1, age is %2").arg(name).arg(age);
    qDebug() << QObject::tr("更改后的str为：") << str;
    str = "%1 %2";
    qDebug() << str.arg("%1f","hello");         //"%1f hello"
    qDebug() << str.arg("%1f").arg("hello");    //"hellof %2"
    str = QString("ni%1").arg("hi",5,'*');
    qDebug() << QObject::tr("设置字段宽度为5，使用'*'填充：") << str;//"ni***hi"
    qreal value = 123.456;
    str = QString("number: %1").arg(value,0,'f',2);
    qDebug() << QObject::tr("设置小数点位数为两位：") << str;  //"number: 123.46"
    //执行下面一行代码，结果为number:123.46不会显示引号
    qDebug() << QObject::tr("将str转换为const char * :") << qPrintable(str);


    return a.exec();
}





























