#ifndef LTCOLOR_COLORDESKTOP_H
#define LTCOLOR_COLORDESKTOP_H

#include <QWidget>
#include <QMouseEvent>
#include <QImage>
#include <QColor>
#include "DetailWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ColorDesktop; }
QT_END_NAMESPACE

/**
 * 截屏类
 */
class ColorDesktop : public QWidget {
Q_OBJECT

public:
    explicit ColorDesktop(QWidget *parent = nullptr);

    ~ColorDesktop() override;

    /**
     * 鼠标点击事件，保存当前位置像素点颜色，并更新主窗口数据
     */
    void mousePressEvent(QMouseEvent *event)override;

    /**
     * 鼠标移动事件，重绘放大镜窗口
     */
    void mouseMoveEvent(QMouseEvent *event)override;

    void exit();

    /**
     * getters and setters
     */
    const QImage &getImage() const;

    void setImage(const QImage &image);

    const QColor &getColor() const;

    void setColor(const QColor &color);

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);

signals:
    void clicked();
private:
    Ui::ColorDesktop *ui;
    /* 放大镜窗口 */
    DetailWidget *widget;
    /* 截屏 */
    QImage image;
    /* 鼠标点击时拾取到的颜色 */
    QColor color;
    /* 屏幕宽高 */
    int height;
    int width;
};


#endif //LTCOLOR_COLORDESKTOP_H
