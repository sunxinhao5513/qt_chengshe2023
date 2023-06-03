#include "bird.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>

PacbirdClass::PacbirdClass():
    birdImage(new QPixmap), superTimer(new QTimer)
{
    birdImage->load(":/resource/images/456px-Pacman.svg.png");
    setPixmap(*birdImage);
    setScale(0.08);
    setPos(375, 275);
    connect(superTimer, &QTimer::timeout, this, &PacbirdClass::offSuper);
}

bool PacbirdClass::isSuper() const{
    return super;
}

void PacbirdClass::onSuper(){
    super = 1;
    superTimer->start(4000);
    setScale(0.15);
}

void PacbirdClass::offSuper(){
    super = 0;
    superTimer->stop();
    setScale(0.08);
}

void PacbirdClass::updatePosition(){
    speed += 1;
    setPos(x(), y() + speed * 2 / 3);
}

void PacbirdClass::flap(){
    speed -= 20;
}

PacbirdClass::~PacbirdClass(){
    delete birdImage;
    delete superTimer;
}
