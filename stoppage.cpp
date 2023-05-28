#include "stoppage.h"
#include "ui_stoppage.h"

stoppage::stoppage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stoppage)
{
    ui->setupUi(this);
}

stoppage::~stoppage()
{
    delete ui;
}
