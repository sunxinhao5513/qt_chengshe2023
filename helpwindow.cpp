#include "helpwindow.h"
#include "ui_helpwindow.h"

helpwindow::helpwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::helpwindow)
{
    ui->setupUi(this);
    this->resize(QSize(600,300));
    ui->helptext->insertPlainText("点击按钮以操纵角色跳跃");
}

helpwindow::~helpwindow()
{
    delete ui;
}

void helpwindow::on_pushButton_clicked()
{
    this->close();
}
