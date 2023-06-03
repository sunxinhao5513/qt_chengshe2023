#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bird.h"
#include "ghost.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include "stoppage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), bird(new PacbirdClass),
      dropTimer(new QTimer)
{
    resize(1000, 700);
    setWindowTitle("game");
    init();
    action();


}

void MainWindow::init(){
    ui->setupUi(this);
    scene->setSceneRect(0, 0, 800, 600);
    QPixmap backgroundPixmap(":/resource/images/background.png");
    scene->setBackgroundBrush(QBrush(backgroundPixmap));
    ui->graphicsView->setScene(scene);
    life = true;

    scene->addItem(bird);
    connect(this, &MainWindow::lose, this, &MainWindow::Lose);
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
    if(birdPos.y() <= -10 || birdPos.y() >= 650) emit lose();
    for(int i = 0; i < 3; ++i)
        if((detectCollide(bird, topGhost[i]) || detectCollide(bird, bottomGhost[i])) && bird->isSuper() == 0)
            emit lose();
}

void MainWindow::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_Space) {
        bird->flap();
    }
    if (event->key() == Qt::Key_S) {
        disconnect(dropTimer, SIGNAL(timeout()), this, SLOT(advance()));
        //stop->show();
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_S){
        connect(dropTimer, SIGNAL(timeout()), this, SLOT(advance()));
        //stop->close();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton && !life){
        game *g = new game;
        g->show();
        this->close();

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

void MainWindow::Lose()
{
    life = false;
    disconnect(dropTimer, SIGNAL(timeout()), this, SLOT(advance()));
    board = new ScoreBoard;
    scene->addItem(board);
    board->setPos(this->width() * 0.45, 365);


    over = new GameOver;
    scene->addItem(over);
    over->setPos(this->width() * 0.45, 40);

//    ExitButton *exBtn = new ExitButton(":/resource/images/exitbutton.png");
//    exBtn->setParent(ui->graphicsView);

//    QPoint pos = ui->graphicsView->pos();
//    exBtn->resize(60, 40);
//    exBtn->move(pos.x()+this->width() - 120, pos.y() + 10);

//    connect(exBtn, &QPushButton::clicked, this, &QMainWindow::close);


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


