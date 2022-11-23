#include "DetailWidget.h"
#include "ui_DetailWidget.h"


DetailWidget::DetailWidget(QWidget *parent) :QWidget(parent), ui(new Ui::DetailWidget) {
    ui->setupUi(this);
    this->BLACK = new QColor(0,0,0);
    this->BLUE = new QColor(26,115,232);
    this->resize(150,150);
    this->move(0,0);
    this->pen.setColor(*this->BLUE);
}

DetailWidget::~DetailWidget() {
    delete BLUE;
    delete BLACK;
    delete ui;
}

void DetailWidget::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    int i;
    int startX;
    int j;
    int startY;
    for(i = 0,startX = x-7;i<=14;i++,startX++){
        for(j = 0,startY = y-7;j<=14;j++,startY++){
            if(startX<0||startX>=this->width||startY<0||startY>=this->height){
                painter.fillRect(i*10,j*10,10,10,*this->BLACK);
            }else{
                painter.fillRect(i*10,j*10,10,10,this->image->pixelColor(startX,startY));
            }
        }
    }
    /* 绘制窗口中心的蓝色小方块 */
    painter.setPen(this->pen);
    painter.drawLine(70,70,80,70);
    painter.drawLine(70,70,70,80);
    painter.drawLine(70,80,80,80);
    painter.drawLine(80,70,80,80);
}

int DetailWidget::getX() const {
    return x;
}

void DetailWidget::setX(int x) {
    DetailWidget::x = x;
}

int DetailWidget::getY() const {
    return y;
}

void DetailWidget::setY(int y) {
    DetailWidget::y = y;
}

QImage *DetailWidget::getImage() const {
    return image;
}

void DetailWidget::setImage(QImage *image) {
    DetailWidget::image = image;
}


int DetailWidget::getHeight() const {
    return height;
}

void DetailWidget::setHeight(int height) {
    DetailWidget::height = height;
}

int DetailWidget::getWidth() const {
    return width;
}

void DetailWidget::setWidth(int width) {
    DetailWidget::width = width;
}