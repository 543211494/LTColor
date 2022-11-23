#ifndef TEST2_MAINWIDGET_H
#define TEST2_MAINWIDGET_H

#include <QWidget>
#include <QScreen>
#include <QDesktopWidget>
#include <QClipboard>
#include <QTime>
#include <QPixmap>
#include "ColorDesktop.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

//主窗口类
class MainWidget : public QWidget {
Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

    ~MainWidget() override;

    /**
     * 退出窗口
     */
    void exit();

    /**
     * 打开截图窗口供用户点击选择像素点
     */
    void chooseColor();

    /**
     * 复制文本
     */
    void copy1();

    /**
     * 复制文本
     */
    void copy2();
public slots:
    /**
     * 更新数据
     */
    void update();

private:
    Ui::MainWidget *ui;
    ColorDesktop *desktop;
};


#endif //TEST2_MAINWIDGET_H
