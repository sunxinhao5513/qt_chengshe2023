#ifndef STOPPAGE_H
#define STOPPAGE_H

#include <QWidget>

namespace Ui {
class stoppage;
}

class stoppage : public QWidget
{
    Q_OBJECT

public:
    explicit stoppage(QWidget *parent = nullptr);
    ~stoppage();

private:
    Ui::stoppage *ui;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private slots:


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // STOPPAGE_H
