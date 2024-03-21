#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "enemy.h"

Player::Player()
{
    //Creating the player
    QPixmap pixmap1("C:\\Users\\mahin\\Desktop\\Uni\\Spring 2024\\CS 2 Lab\\Assignments\\Assignment 2\\Assignment 2\\ChickenInvaders\\ChickenInvaders\\ship.PNG");
    pixmap1 = pixmap1.scaledToWidth(75);
    pixmap1 = pixmap1.scaledToHeight(75);
    this->setPixmap(pixmap1);
    this->setPos(400,500); //setting position to bottom centre

}


void Player::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        setPos(x()-30, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+30, y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-30);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+30);
    }

}

void Player::createEnemy()
{
   enemy * chicken = new enemy();
   scene()->addItem(chicken);
}
