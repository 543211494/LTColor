#include "ColorDesktop.h"
#include "ui_ColorDesktop.h"


ColorDesktop::ColorDesktop(QWidget *parent) : QWidget(parent), ui(new Ui::ColorDesktop) {
    ui->setupUi(this);
    this->setMouseTracking(true);
    this->widget = new DetailWidget(this);
}

ColorDesktop::~ColorDesktop() {
    delete widget;
    delete ui;
}

const QImage &ColorDesktop::getImage() const {
    return image;
}

void ColorDesktop::setImage(const QImage &image) {
    ColorDesktop::image = image;
}

const QColor &ColorDesktop::getColor() const {
    return color;
}

void ColorDesktop::setColor(const QColor &color) {
    ColorDesktop::color = color;
}

int ColorDesktop::getHeight() const {
    return height;
}

void ColorDesktop::setHeight(int height) {
    ColorDesktop::height = height;
}

int ColorDesktop::getWidth() const {
    return width;
}

void ColorDesktop::setWidth(int width) {
    ColorDesktop::width = width;
}

void ColorDesktop::mousePressEvent(QMouseEvent *event) {
    /* 隐藏当前全屏窗口 */
    this->setVisible(false);
    /* 保存颜色信息 */
    this->color = this->image.pixelColor(event->globalX(),event->globalY());
    /* 发送信号更新主窗口数据 */
    emit this->clicked();
}

void ColorDesktop::mouseMoveEvent(QMouseEvent *event) {
    /* 移动放大镜窗口以避开鼠标 */
    if(event->globalY()<=this->width/2&&event->globalX()<=this->height/2){
        this->widget->move(this->width-150,this->height-150);
    }else{
        this->widget->move(0,0);
    }
    /* 更新信息并重绘放大镜窗口 */
    this->widget->setX(event->globalX());
    this->widget->setY(event->globalY());
    this->widget->setImage(&this->image);
    this->widget->setWidth(this->width);
    this->widget->setHeight(this->height);
    this->widget->repaint();
}

void ColorDesktop::exit() {
    this->widget->close();
    this->close();
}

