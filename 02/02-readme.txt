------------------------------------
.pro文件需要：
	greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

命令行编译指令：

        从.ui文件生成头文件：
	uic -o ui_hellodialog.h hellodialog.ui
        工程编译相关命令：

	//生成.pro文件
	qmake -project

	qmake
	mingw32-make

------------------------------------

02-01	Qt Widgets Application
02-02	Empty qmake Project
02-03	main.cpp+命令行编译
02-04	02-3 + .ui
02-05	自定义c++类