#ifndef GAME_H
#define GAME_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QWidget
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();

private:
    Ui::game *ui;

    // QWidget interface
protected:

private slots:
    void on_helpbutton_clicked();
    void on_quitbutton_clicked();
    void on_startbutton_clicked();
    void on_pushButton_clicked();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // GAME_H
