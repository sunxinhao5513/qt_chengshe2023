#include "changewindow.h"
#include "ui_changewindow.h"
#include "qradiobutton.h"
#include <QButtonGroup>
#include "game.h"
#include <QPainter>
#include <QPaintEvent>

changewindow::changewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changewindow)
{
    ui->setupUi(this);
    yinx->addButton(ui->yinxiaok);
    yinx->addButton(ui->yinxiaog);
    ui->yinxiaok->setChecked(true);
}
void changewindow::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/resource/images/Set.png"));
}
changewindow::~changewindow()
{
    delete ui;
}
void changewindow::on_back_clicked()
{
    this->close();
}
void changewindow::on_yinxiaok_clicked(bool checked)
{
    if(checked == true)
    {
        music->play();
        music->setLoopCount(music->Infinite);
    }
    else music->stop();
}
void changewindow::on_yinxiaog_clicked(bool checked)
{
    if(checked == true) music->stop();
    else
    {
        music->play();
        music->setLoopCount(music->Infinite);
    }
}
