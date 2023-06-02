#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QGraphicsColorizeEffect>
#include <QPixmap>

class GhostClass:public QGraphicsPixmapItem{
public:
    GhostClass(int num, bool flag);
    void updatePosition();//更新ghost位置
    ~GhostClass();

private:
    QPixmap* ghostImage;//TODO：ghost的造型
    QGraphicsColorizeEffect* color;//颜色效果
    void init(int num = 0);//初始化ghost
    int speed = 4;//速度
    int flag = 0;//鬼在上方还是下方
};

#endif // GHOST_H
