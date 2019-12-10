#表明该项目要构建库文件
TEMPLATE     = lib
#qmake要创建一个插件
CONFIG	    += plugin
#项目文件路径
INCLUDEPATH += ../regexpwindow
#头文件
HEADERS	     = regexpplugin.h
#源文件
SOURCES	     = regexpplugin.cpp
#指定了产生的dll文件的名字
TARGET	     = regexpplugin
#指定了生成的dll文件所在的目录
DESTDIR	     = ../plugins
