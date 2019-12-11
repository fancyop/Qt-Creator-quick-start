
10-01	基本绘制和填充（含渐变）
		QPen QBrush 
		QPainter： drawArc drawRect drawEllipse drawPolygon fillRect
		eraseRect drawLine drawText setBrush setColorAt
		线性渐变 辐射渐变 锥形渐变
		QLinearGradient QRadialGradient QConicalGradient
10-02	坐标系统
		QPainter：save restore
		坐标平移：translate
		坐标旋转：rotate
10-03	坐标系统
		QPainter：setWindow 设置逻辑坐标起点和将宽高等分个数
		setMouseTracking(true) 不按下按键也能触发鼠标移动事件
10-04	坐标系统-模拟时钟旋转
		QPainter：setWorldTransform 
		QTransform：translate scale rotate
10-05	其他绘制-绘制文本
		QPainter：drawText
		QFont：setUnderline setCapitalization setCapitalization
10-06	绘制路径
		QPainterPath（类似QML里的canvas）：moveTo lineTo  addEllipse
		cubicTo(三阶贝赛尔) translate
10-07	绘制路径
		QPainterPath：setFillRule(两形状相交显示规则)
10-08	绘制图像-手动绘制作为图像
		QImage QPixmap QBitmap QPicture
		QPainter：begin（指定绘制设备） end
10-09	绘制图像-显示外部图像-Image
		QPainter drawImage
		QImage load
		QTransform transform
10-10	绘制图像-显示外部图像-Pixmap
		QPixmap：load 
		获取截屏图片
10-11	复合模式
		QPainter：setCompositionMode(图画叠加规则)
10-12	双缓冲绘图