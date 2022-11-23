#ifndef LTCOLOR_DETAILWIDGET_H
#define LTCOLOR_DETAILWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QImage>


QT_BEGIN_NAMESPACE
namespace Ui { class DetailWidget; }
QT_END_NAMESPACE

/**
 * 放大镜窗口类
 */
class DetailWidget : public QWidget {
Q_OBJECT

public:
    explicit DetailWidget(QWidget *parent = nullptr);

    ~DetailWidget() override;

    /**
     *
     * 覆写绘图函数，副窗口鼠标移动时调用，更新放大镜窗口
     * @param e
     */
    void paintEvent(QPaintEvent *e)override;

    /**
     * getters and setters
     */
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    QImage *getImage() const;

    void setImage(QImage *image);

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);

private:
    Ui::DetailWidget *ui;
    /* 颜色常量 */
    QColor *BLACK;
    QColor *BLUE;
    /* 画笔 */
    QPen pen;
    /* 截屏 */
    QImage *image;
    /* 屏幕的宽度和高度 */
    int height;
    int width;
    /* 鼠标的x,y坐标 */
    int x;
    int y;
};


#endif //LTCOLOR_DETAILWIDGET_H
