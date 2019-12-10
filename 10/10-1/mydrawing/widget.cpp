#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//绘制直线
    QPainter painter(this);
    painter.drawLine(QPoint(0,0),QPoint(100,100));

//绘制弧形
    //创建画笔： 颜色  宽度  风格  端点风格  连接风格
    QPen pen(Qt::green,6,Qt::DashDotLine,Qt::RoundCap,Qt::BevelJoin);
    //使用画笔
    painter.setPen(pen);
    //xp(0.), yp(0.), w(0.), h(0.)
    QRectF rectangle(70.0,40.0,80.0,80.0);
    int starAngle = 0*16;
    int spanAngle = 270*16;
    //绘制圆弧
    painter.drawArc(rectangle,starAngle,spanAngle);

//绘制矩形
    //重新设置画笔
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    //绘制一个矩形
    painter.drawRect(160,20,50,40);

//绘制椭圆
    //创建画刷
    QBrush brush(QColor(0,0,255),Qt::CrossPattern);
    //使用画刷
    painter.setBrush(brush);
    //绘制椭圆
    painter.drawEllipse(220,20,50,50);

//绘制多边形
    //设置纹理
    brush.setTexture(QPixmap("../mydrawing/image.png"));
    //重新使用画刷
    painter.setBrush(brush);
    //定义四个点
    static const QPointF points[4] = {
        QPointF(270.0, 180.0),
        QPointF(290.0, 10.0),
        QPointF(350.0, 30.0),
        QPointF(390.0, 170.0),
    };
    //使用4个点绘制多边形
    painter.drawPolygon(points,4);

    //使用画刷填充一个矩形区域
    painter.fillRect(QRect(10,140,150,20),QBrush(Qt::darkYellow));
    //擦除一个矩形区域的内容
    painter.eraseRect(QRect(300,50,100,80));

//渐变填充
    //线性渐变
    QLinearGradient linearGradient(QPoint(40,190),QPoint(70,190));
    //插入颜色
    linearGradient.setColorAt(0,Qt::yellow);
    linearGradient.setColorAt(0.5,Qt::red);
    linearGradient.setColorAt(1,Qt::green);
    //指定渐变区域以外的区域的扩散方式
    linearGradient.setSpread(QGradient::ReflectSpread);
    //使用渐变作为画刷
    painter.setBrush(linearGradient);
    painter.drawRect(10,170,90,40);

//辐射渐变
    QRadialGradient radialGradient(QPointF(200,190),50,QPointF(200,150));
    radialGradient.setColorAt(0,QColor(125,0,0,150));
    radialGradient.setColorAt(1,QColor(0,0,0,50));
    painter.setBrush(radialGradient);
    painter.drawEllipse(QPointF(200,190),50,50);
    //辐射渐变起止坐标连线
    painter.drawLine(QPoint(200,190),QPoint(200,150));

//锥形渐变
    QConicalGradient conicalGradient(QPointF(350,190),60);
    conicalGradient.setColorAt(0.2,Qt::cyan);
    conicalGradient.setColorAt(0.9,Qt::black);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(350,190),50,50);

    painter.drawLine(QPoint(350,190),QPoint(350,140));

//画笔使用线性渐变来绘制直线和文字
    //    PadSpread,
    //    ReflectSpread,
    //    RepeatSpread
    //设置线性填充的扩散方式
    linearGradient.setSpread(QGradient::ReflectSpread);
    painter.setPen(QPen(linearGradient,2));
    painter.drawLine(0,280,100,280);
    painter.drawText(150,280,tr("hello Qt!"));

//辐射渐变


}


















