
07-01	对象模型--信号和槽：MyDialog发送信号到Widget的槽
	信号signals、槽slots、关联connect、发射信号emit
07-02	对象模型--信号和槽的自动关联、断开关联
	QPushButton：myButton
	自定义槽：on_myButton_clicked()
07-03	对象模型--属性系统：Q_PROPERTY
	注册属性userName：实现READ读函数、实现WRITE写函数、声明NOTIFY通知消息
    	Q_PROPERTY(QString userName READ getUserName 
	WRITE setUserName NOTIFY userNameChanged)
07-04	对象模型--对象树与拥有权
	children()
	创建子部件指定父部件，创建子部件不指定父部件
07-05	容器类--顺序容器
	QList: replace append prepend takeAt size at contains count indexOf
07-06	容器类--map容器
	一键多值
	QMap value insert  insertMulti
	QMultiMap insert values
07-07	容器类--List迭代器（Java风格迭代器）
	只读迭代器，遍历List容器
	QListIterator : hasNext next hasPrevious previous
	读写迭代器，遍历List容器
	QMutableListIterator : hasPrevious previous remove  setValue toFront  hasNext next
07-08	容器类--map迭代器（Java风格迭代器）
	QMapIterator、QMutableMapIterator
07-09	容器类（STL风格迭代器）
	QMapIterator、QMutableMapIterator
07-10	foreach关键字--进行容器顺序遍历
	foreach(QString str, list){		//从list中获取每一项
		qDebug() << str;		//结果为A,B,C
	}
07-11	容器类--通用算法
	algorithm
	算法：copy/equal/fill/count/lower_bound/sort/stable_sort/greater/swap
07-12	容器类--QString
	编辑操作：append replace  insert trimmed  simplified split isNull isEmpty
	查询操作：right left mid number toFloat toUpper toLower arg ，qPrintable
07-13	QVariant：toInt toFloat toString type value canConvert convert 
07-14	正则表达式
	QRegExp：setPattern indexIn setPattern replace setPatternSyntax exactMatch
	cap：返回第n个子表达式捕获的文本。整个匹配项具有索引0，带圆括号的子表达式具
	有从1开始的索引（不包括未捕获的圆括号）。
	setCaseSensitivity