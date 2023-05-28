#ifndef GAMEINIT_H
#define GAMEINIT_H

#include <QWidget>

namespace Ui {
class gameinit;
}

class gameinit : public QWidget
{
    Q_OBJECT

public:
    explicit gameinit(QWidget *parent = nullptr);
    ~gameinit();

private:
    Ui::gameinit *ui;
};

#endif // GAMEINIT_H
