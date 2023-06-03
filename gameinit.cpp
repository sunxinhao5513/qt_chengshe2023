#include "gameinit.h"
#include "ui_gameinit.h"
#include "stoppage.h"

gameinit::gameinit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameinit)
{
    ui->setupUi(this);
    this->resize(QSize(1000,700));
}

gameinit::~gameinit()
{
    delete ui;
}
