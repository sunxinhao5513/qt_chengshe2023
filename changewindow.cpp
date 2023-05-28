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
    QButtonGroup *yinx=new QButtonGroup(this);
    yinx->addButton(ui->yinxiaok);
    yinx->addButton(ui->yinxiaog);
}
void changewindow::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/resource/images/shezhi.png"));
}
changewindow::~changewindow()
{
    delete ui;
}

void changewindow::on_yinxiaok_clicked()
{
    game*start=(game*)parentWidget();
}
