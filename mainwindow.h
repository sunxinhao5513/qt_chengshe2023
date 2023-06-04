#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bird.h"
#include "ghost.h"
#include "dot.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QTextEdit>
#include <QDataStream>
#include <QTextStream>
#include "stoppage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void lose();//lose()为失败信号 //TODO：失败窗口
    void returnTo();

public slots:
    void advance();//更新游戏场景
    void detectLose();//检测是否失败，失败则会释放出信号lose()

private:
    void action();//用于初始化
    void init();//用于初始化
    void keyPressEvent(QKeyEvent* event) override;//检查空格动作
    void mousePressEvent(QMouseEvent *event) override;
    bool detectCollide(const QGraphicsPixmapItem* a, const QGraphicsPixmapItem* b);//检查两物体是否碰撞 //TODO：碰撞的效果展现
    void updatePosition();//更新各物体位置
    void processDots();//处理点的刷新
    void updatescore();//分数更新
    void Lose(); //失败后的事件
    void read_maxscore();
    void write_maxscore();

    Ui::MainWindow *ui;
    QGraphicsScene* scene;//游戏场景
    PacbirdClass* bird;//bird
    GhostClass* topGhost[4];//上面的ghost
    GhostClass* bottomGhost[4];//下面的ghost
    QVector<dotClass*> dots;//dot
    QTimer* dropTimer;//用于更新场景的计时器

    bool life; //游戏是否
    int score = 0;//分数 //TODO：合理的数值设计
    int max_score = 0; //记录最大分数

    // QWidget interface
protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    stoppage* stop = new stoppage;
};//TODO:背景、音乐

#endif // MAINWINDOW_H
