
06-01	事件传递：LineEdit键盘按下事件 --> Widget按键按下事件
	MyLineEdit::keyPressEvent
	Widget::keyPressEvent
06-02	06-01基础+
	事件传递：Widget事件过滤器 --> LineEdit的event()函数事件 --> 
	LineEdit键盘按下事件 --> Widget按键按下事件
	Widget::eventFilter
	MyLineEdit::event
	MyLineEdit::keyPressEvent
	Widget::keyPressEvent
06-03	鼠标及其滚轮事件：
	鼠标按下、鼠标释放、鼠标移动，鼠标双击、鼠标滚轮等事件
	QCursor、QMouseEvent
06-04	键盘按下事件
	QKeyEvent
06-05	键盘事件：keyPressEvent、keyReleaseEvent
06-06	定时器事件：timerEvent
	QTimerEvent
06-07	定时器：显示当前系统时间到lcdNumber，位置随机变化，10s后关闭运行程序
	timerUpdate事件
06-08	事件过滤器与事件的发送：根据部件及其相应设定进行事件监视
	textEdit滚轮放大缩小文本字体：wheelEvent->delta() zoomIn zoomout
	spinBox按下空格部件数值置0-：keyEvent->key() setValue
	eventFilter
	