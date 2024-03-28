#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "healthandscore.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

bullet::bullet()
{
    //bullet picture
    QPixmap pixmap1(":/bullet.PNG");
    pixmap1 = pixmap1.scaledToWidth(75);
    pixmap1 = pixmap1.scaledToHeight(100);
    this->setPixmap(pixmap1);
    this->setPos(325,425);


    //moving upwards
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    qDebug()<<"inside constructor";

}
void bullet::move()
{
    // handling collision with enemy
    QList<QGraphicsItem *> coliding_items=collidingItems();
    for (int i=0,n=coliding_items.size();i<n;i++)
    {
        if (typeid(*(coliding_items[i]))==typeid(enemy))
        {

            scene()->removeItem(coliding_items[i]);
            scene()->removeItem(this);
            delete coliding_items[i];
            delete this;
            score->setPlainText("Score: " + QString::number(++scoreValue)); //updates score

            //to play sound when enemy is destroyed
            QAudioOutput * destroyEnemyoutput = new QAudioOutput();
            destroyEnemyoutput->setVolume(10);
            QMediaPlayer * destroyEnemy = new QMediaPlayer();
            destroyEnemy->setAudioOutput(destroyEnemyoutput);
            destroyEnemy->setSource(QUrl("qrc:/DestroyingEnemySound.mp3"));
            destroyEnemy->play();
            return;
        }
    }

    this->setPos(x(),y()-10);
    if(y() < 0)
    {
        scene()->removeItem(this); //remove bullet when reaches top
        delete this;

    }

}







