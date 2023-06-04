#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H
#include <QSoundEffect>
#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class changewindow;
}

class changewindow : public QWidget
{
    Q_OBJECT

public:
    explicit changewindow(QWidget *parent = nullptr);
    ~changewindow();
    QSoundEffect* music;
private slots:
    void on_yinxiaok_clicked(bool checked);
    void on_yinxiaog_clicked(bool checked);
    void on_back_clicked();
private:
    Ui::changewindow *ui;
    QButtonGroup *yinx=new QButtonGroup(this);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CHANGEWINDOW_H
