#ifndef EXITBUTTON_H
#define EXITBUTTON_H
#include <QDebug>
#include <QWidget>
#include <QPushButton>
class ExitButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit ExitButton(QWidget *parent = nullptr);
    //构造函数 参数1显示的图片路径 参数2按下后的图片路径（用于实现按压de感觉）
    ExitButton(QString normalImg, QString pressImg = "");

    QString normalImgPath;
    QString pressImgPath;
signals:

};

#endif // EXITBUTTON_H
