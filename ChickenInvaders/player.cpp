#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "healthandscore.h"
#include <QMediaPlayer>
#include <QtMultimedia>

Player::Player()
{
    //Creating the player
    QPixmap pixmap1(":/ship.PNG");
    pixmap1 = pixmap1.scaledToWidth(75);
    pixmap1 = pixmap1.scaledToHeight(75);
    this->setPixmap(pixmap1);
    this->setPos(400,500); //setting position to bottom centre

}


void Player::keyPressEvent(QKeyEvent * event)
{
    //handling key presses
    if (event->key() == Qt::Key_Left)
    {
        if(x()>30)
        {
        setPos(x()-30, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(x()<800-100)
        {
        setPos(x()+30, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        if(y()>20)
        {
        setPos(x(), y()-30);
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if(y()<600-90)
        {
        setPos(x(), y()+30);
        }
    }
    else if(event->key()== Qt::Key_Space)
    {
        bullet * b = new bullet();
        b->setPos(x()+38,y()-70);
        scene()->addItem(b);

        QMediaPlayer * bulletSound = new QMediaPlayer; //playing sound when bullet is emitted
        bulletSound->setSource(QUrl(":/bulletsound.mp3"));
        bulletSound->play();

    }

}



void Player::createEnemy()
{
    if (healthValue>=1) //to stop creating enemies when game is over
    {
       enemy * chicken = new enemy();
       scene()->addItem(chicken);
    }
}

