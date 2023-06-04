#include "helpwindow.h"
#include "ui_helpwindow.h"
#include <QPaintEvent>
#include <QPainter>

helpwindow::helpwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::helpwindow)
{
    ui->setupUi(this);
    this->resize(QSize(600,400));
    setWindowTitle("help");
}

helpwindow::~helpwindow()
{
    delete ui;
}
void helpwindow::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/resource/images/help.png"));
}

void helpwindow::on_back_clicked()
{
    this->close();
}

