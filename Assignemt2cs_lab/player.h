#ifndef PLAYER_H
#define PLAYER_H

#include <QDialog>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>


namespace Ui {
class Player;
}

class Player : public QDialog
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);
    ~Player();

private:
    Ui::Player *ui;
public slots:
    void keyPressEvent(QKeyEvent * event);


};

#endif // PLAYER_H
