#include "stoppage.h"
#include "ui_stoppage.h"
#include <QPaintEvent>
#include <QPainter>
#include "mainwindow.h"

stoppage::stoppage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stoppage)
{
    ui->setupUi(this);
    setWindowTitle("pause");
    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QColor("white")));
    fmt.setBackground(QBrush(QColor("black")));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
    ui->plainTextEdit->appendPlainText("press c to continue");
    ui->plainTextEdit->setReadOnly(true);
}
void stoppage::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/resource/images/765395.jpg"));
}
void stoppage::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_C){
        this->close();
    }
}
stoppage::~stoppage()
{
    delete ui;
}



