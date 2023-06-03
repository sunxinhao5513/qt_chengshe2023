#include "dot.h"
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>

dotClass::dotClass(): dotImage(new QPixmap){
    dotImage->load("../Bird/OIP.png");
    setPixmap(*dotImage);
    setScale(0.03);
    int randomx = QRandomGenerator::global()->bounded(700) + 50 + 800;
    int randomy = QRandomGenerator::global()->bounded(500) + 50;
    int randnum = QRandomGenerator::global()->bounded(100);
    if(randnum <= 4){
        capsule = 1;
        setScale(0.08);
    }
    setPos(randomx, randomy);
}

bool dotClass::isCapsule() const{
    return capsule;
}

void dotClass::reset(){
    int randomx = QRandomGenerator::global()->bounded(700) + 50 + 800;
    int randomy = QRandomGenerator::global()->bounded(500) + 50;
    int randnum = QRandomGenerator::global()->bounded(100);
    if(randnum <= 4){
        capsule = 1;
        setScale(0.08);
    }
    else{
        capsule = 0;
        setScale(0.05);
    }
    setPos(randomx, randomy);
}

void dotClass::updatePosition(){
    setPos(x() - speed, y());
    if(x() < -50){
        int randomnum = QRandomGenerator::global()->bounded(500) + 50;
        setPos(800, randomnum);
    }
}

dotClass::~dotClass(){
    delete dotImage;
}
