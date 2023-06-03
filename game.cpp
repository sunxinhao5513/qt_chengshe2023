#include "game.h"
#include "ui_game.h"
#include <QPainter>
#include <QPaintEvent>
#include <QSoundEffect>
#include <QComboBox>
#include "helpwindow.h"
#include "gameinit.h"
#include "changewindow.h"
#include <QPalette>

game::game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game)
{
    setAutoFillBackground(true);
    ui->setupUi(this);
    this->resize(QSize(1000,700));
    QSoundEffect *music=new QSoundEffect();
    music->setSource(QUrl::fromLocalFile("://music/Flappy-Bird-Theme-Song.wav"));
    music->setLoopCount(-1);
    music->play();

}
void game::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/resource/images/765395.jpg"));
}

game::~game()
{
    delete ui;
}


void game::on_helpbutton_clicked()
{
    helpwindow*helpwind=new helpwindow();
    helpwind->show();
}

void game::on_quitbutton_clicked()
{
    this->close();
}

void game::on_startbutton_clicked()
{
    this->close();
    MainWindow *newgame=new MainWindow();
    newgame->show();
}

void game::on_pushButton_clicked()
{
    changewindow*changewind=new changewindow();
    changewind->show();
}
