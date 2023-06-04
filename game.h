#ifndef GAME_H
#define GAME_H
#include <QSoundEffect>
#include <QWidget>
#include "mainwindow.h"
#include "helpwindow.h"
#include "changewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QWidget
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();
    QSoundEffect* music = new QSoundEffect();

private:
    Ui::game *ui;

    // QWidget interface
protected:
    MainWindow* window;
    helpwindow* helpwind = new helpwindow();
    changewindow* changewind=new changewindow();

private slots:
    void on_helpbutton_clicked();
    void on_quitbutton_clicked();
    void on_startbutton_clicked();
    void on_pushButton_clicked();
    void handleReturnTo();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // GAME_H
