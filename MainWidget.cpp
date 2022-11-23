#include "MainWidget.h"
#include "ui_MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget) {
    ui->setupUi(this);
    //初始化设置
    ui->lineEdit_1->setReadOnly(true);
    ui->lineEdit_1->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_1->setText("255,255,255");
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_2->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_2->setText("#FFFFFF");
    //获取屏幕长宽
    QScreen *screen = QGuiApplication::primaryScreen();
    this->desktop = new ColorDesktop(nullptr);
    this->desktop->setVisible(false);
    this->desktop->setWidth(screen->size().width());
    this->desktop->setHeight(screen->size().height());
    this->setWindowTitle("LTColor");
    /* 信号 */
    connect(ui->exit, &QPushButton::clicked, this, &MainWidget::exit);
    connect(ui->getColor, &QPushButton::clicked, this, &MainWidget::chooseColor);
    connect(this->desktop,&ColorDesktop::clicked,this,&MainWidget::update);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&MainWidget::copy1);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWidget::copy2);
}

MainWidget::~MainWidget() {
    delete ui;
    delete desktop;
}

void MainWidget::exit() {
    this->desktop->exit();
    this->close();
}

void MainWidget::chooseColor() {
    this->setVisible(false);
    /* 延时600毫秒 */
    QTime timer = QTime::currentTime().addMSecs(600);
    while( QTime::currentTime() < timer );
    /* 抓取全屏并保存 */
    QPixmap pixmap = QGuiApplication::primaryScreen()->grabWindow(0);
    this->desktop->setImage(pixmap.toImage());
    /* 全屏化展示截图供用户选择点 */
    this->desktop->resize(this->desktop->getWidth(),this->desktop->getHeight());
    this->desktop->setAutoFillBackground(true);
    QPalette palette = this->desktop->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(pixmap.scaled(
                             this->desktop->size(),
                             Qt::IgnoreAspectRatio,
                             Qt::FastTransformation)));
    this->desktop->setPalette(palette);
    this->desktop->showFullScreen();
}

void MainWidget::update() {
    this->setVisible(true);
    //更新文本
    QString RGB = QString("%1,%2,%3")
            .arg(this->desktop->getColor().red())
            .arg(this->desktop->getColor().green())
            .arg(this->desktop->getColor().blue());
    this->ui->lineEdit_1->setText(RGB);
    this->ui->lineEdit_2->setText(this->desktop->getColor().name().toUpper());
    //更新色块
    QString style = "background-color:rgb(";
    style.append(RGB).append(')');
    this->ui->Color->setStyleSheet(style);
    this->ui->Color->setAttribute(Qt::WA_StyledBackground);
}

void MainWidget::copy1() {
    QClipboard *clip = QApplication::clipboard();
    clip->setText(this->ui->lineEdit_1->text());
}

void MainWidget::copy2() {
    QClipboard *clip = QApplication::clipboard();
    clip->setText(this->ui->lineEdit_2->text());
}

