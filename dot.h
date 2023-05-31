#ifndef DOT_H
#define DOT_H
#include<QGraphicsPixmapItem>

class dotClass:public QGraphicsPixmapItem{
public:
    dotClass();
    void updatePosition();//更新dot位置
    void reset();//dot的刷新
    bool isCapsule() const;//判断dot是否为capsule //capsule：进入超级模式的道具 // TODO：capsule的造型
    ~dotClass();
private:
    QPixmap* dotImage;
    int speed = 4;//速度
    bool capsule = 0;//是否为capsule
};

#endif // DOT_H
