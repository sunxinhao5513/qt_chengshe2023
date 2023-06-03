#include "ghost.h"
#include <QPixmap>
#include <QRandomGenerator>
#include <QGraphicsColorizeEffect>

GhostClass::GhostClass(int num, bool _flag):ghostImage(new QPixmap), color(new QGraphicsColorizeEffect), flag(_flag){
    if(flag == 0) ghostImage->load("../Bird/Studio_Project_(1).png");
    else ghostImage->load("../Bird/Studio_Project_(1) (1).png");
    setPixmap(*ghostImage);
    setScale(0.3);
    setGraphicsEffect(color);
    init(num);
}

void GhostClass::init(int num){
    int randnum = QRandomGenerator::global()->bounded(3);
    if(randnum == 0){
        if(color != nullptr) delete color;
        color = nullptr;
        setGraphicsEffect(color);
    }
    if(randnum == 1){
        if(color == nullptr) color = new QGraphicsColorizeEffect;
        QColor temp = Qt::yellow;
        temp = temp.darker(125);
        color->setColor(temp);
        setGraphicsEffect(color);
    }
    else if(randnum == 2){
        if(color == nullptr) color = new QGraphicsColorizeEffect;
        QColor temp = Qt::green;
        temp = temp.darker(125);
        color->setColor(temp);
        setGraphicsEffect(color);
    }
    if(flag == 0){
        int randomnum = QRandomGenerator::global()->bounded(175);
        setPos(800 + 300 * num, -150 + randomnum);
    }
    else{
        int randomnum = QRandomGenerator::global()->bounded(175);
        setPos(800 + 300 * num, 550 - randomnum);
    }
}

void GhostClass::updatePosition(){
    setPos(x() - speed, y());
    if(x() < -150) init();
}

GhostClass::~GhostClass(){
    delete ghostImage;
    delete color;
}
