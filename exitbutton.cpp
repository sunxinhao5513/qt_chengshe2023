#include "exitbutton.h"
#include <QDebug>
ExitButton::ExitButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug() << "failed!!";
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    //虚化按钮背景
    //this->setStyleSheet("QPushButton(border:0px)");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

