#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H

#include <QWidget>

namespace Ui {
class changewindow;
}

class changewindow : public QWidget
{
    Q_OBJECT

public:
    explicit changewindow(QWidget *parent = nullptr);
    ~changewindow();

private slots:
    void on_yinxiaok_clicked();

private:
    Ui::changewindow *ui;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CHANGEWINDOW_H
