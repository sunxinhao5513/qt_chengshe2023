#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bird.h"
#include "ghost.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), bird(new PacbirdClass),
      dropTimer(new QTimer)
{
    init();
    action();
}

void MainWindow::init(){
    ui->setupUi(this);
    scene->setSceneRect(0, 0, 800, 600);
    scene->setBackgroundBrush(Qt::blue);
    ui->graphicsView->setScene(scene);
    scene->addItem(bird);
    for(int i = 0; i < 3; ++i){
        topGhost[i] = new GhostClass(i, 0);
        bottomGhost[i] = new GhostClass(i, 1);
        scene->addItem(bottomGhost[i]);
        scene->addItem(topGhost[i]);
    }
    for(int i = 0; i < 10; ++i){
        dotClass* newDot = new dotClass;
        scene->addItem(newDot);
        dots.push_back(newDot);
    }
}

void MainWindow::action(){
    connect(dropTimer, SIGNAL(timeout()), this, SLOT(advance()));
    dropTimer->start(30);
}

void MainWindow::detectLose(){
    QPointF birdPos = bird->pos();
    if(birdPos.y() <= 0 || birdPos.y() >= 600) emit lose();
    for(int i = 0; i < 3; ++i)
        if((detectCollide(bird, topGhost[i]) || detectCollide(bird, bottomGhost[i])) && bird->isSuper() == 0)
            emit lose();
}

void MainWindow::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_Space) {
        bird->flap();
    }
}

bool MainWindow::detectCollide(const QGraphicsPixmapItem* a, const QGraphicsPixmapItem* b){
    QRectF aBox = a->boundingRect();
    aBox = a->mapRectToScene(aBox);
    QRectF bBox = b->boundingRect();
    bBox = b->mapRectToScene(bBox);
    if(aBox.intersects(bBox)) return 1;
    else return 0;
}

void MainWindow::advance(){
    score += 1;
    updatePosition();
    detectLose();
    processDots();
}

void MainWindow::updatePosition(){
    bird->updatePosition();
    for(int i = 0; i < 3; ++i){
        topGhost[i]->updatePosition();
        bottomGhost[i]->updatePosition();
    }
    for(auto& dot :dots)
        dot->updatePosition();
}

void MainWindow::processDots(){
    for(auto& dot :dots){
        while(true){
            bool flag = 1;
            for(int i = 0; i < 3; ++i)
                if(detectCollide(dot, topGhost[i]) || detectCollide(dot, bottomGhost[i])){
                    dot->reset();
                    flag = 0;
                    break;
                }
            if(flag) break;
        }
        for(int i = 0; i < 3; ++i)
            while(detectCollide(dot, topGhost[i]) || detectCollide(dot, bottomGhost[i])){
                dot->reset();
            }
        if(detectCollide(dot, bird)){
            if(dot->isCapsule()) bird->onSuper();
            score += 10;
            dot->reset();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete bird;
    for(int i = 0; i < 3; ++i){
        delete topGhost[i];
        delete bottomGhost[i];
    }
    delete dropTimer;
}
