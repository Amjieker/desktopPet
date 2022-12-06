#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    int idx;
    QPoint diff_;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};
#endif // WIDGET_H
