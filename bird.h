#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class PacbirdClass:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    PacbirdClass();//TODO:bird的造型
    void updatePosition();//更新bird位置
    void flap();//向上跳
    bool isSuper() const;//判断当前是否处于超级状态 //超级状态：bird变大，并且可以穿过ghost //TODO:ghost的状态变化
    ~PacbirdClass();

public slots:
    void onSuper();//开启超级模式
    void offSuper();//关闭超级模式

private:
    QPixmap* birdImage;//TODO:动图
    int speed = 0;//速度
    bool super = 0;//超级模式
    QTimer* superTimer;//计时器
};

#endif // BIRD_H
