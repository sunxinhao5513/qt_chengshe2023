#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>

namespace Ui {
class helpwindow;
}

class helpwindow : public QWidget
{
    Q_OBJECT

public:
    explicit helpwindow(QWidget *parent = nullptr);
    ~helpwindow();

private slots:

    void on_back_clicked();

private:
    Ui::helpwindow *ui;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // HELPWINDOW_H
