#include "player.h"
#include "ui_player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

Player::Player(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);
    setPixmap(QPixmap(“chicken.PNG”));
}
void Player::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        fsetpos(x()-30, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        fsetpos(x()+30, y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        fsetpos(x(), y()-30);
    }
    else if (event->key() == Qt::Key_Down)
    {
        fsetpos(x(), y()+30);
    }

}

Player::~Player()
{
    delete ui;
}
