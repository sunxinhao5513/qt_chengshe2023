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
    void on_pushButton_clicked();

private:
    Ui::helpwindow *ui;
};

#endif // HELPWINDOW_H
