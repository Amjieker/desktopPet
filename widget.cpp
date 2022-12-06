#include "widget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
#include <QResource>
#include <QDir>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QResource::registerResource("./static.rcc");
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlags (windowFlags () | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);
    setMinimumSize(1400, 1400);
    auto hlayout = new QHBoxLayout(this);
    auto l = new QLabel();
    hlayout->addWidget(l);
    this->idx = 1;
    l->setStyleSheet(QString("background: url(:/static/nilu/%1.png) no-repeat;").arg(this->idx));
    auto time = new QTimer(this);
    time->setInterval(50);
    connect(time, &QTimer::timeout, this, [this, l]() {
        this->idx = (this->idx + 1 ) % 2971 + 1;
        l->setStyleSheet(QString("background: url(:/static/nilu/%1.png) no-repeat;").arg(this->idx));
    });
    time->start();
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{

    diff_ = event->globalPos() - this->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{

    diff_ = QPoint();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

    this->move(event->globalPos() - this->diff_);
}

