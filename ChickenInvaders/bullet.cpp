#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>

bullet::bullet() :QObject()
{
    //bullet picture
    QPixmap pixmap1("/Users/mac/ChickenInvaders/ChickenInvaders/bullet.jpeg");
    pixmap1 = pixmap1.scaledToWidth(50);
    pixmap1 = pixmap1.scaledToHeight(50);
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
    QList<QGraphicsItem *> coliding_items=collidingItems();
    for (int i=0,n=coliding_items.size();i<n;i++)
    {
        if (typeid(*(coliding_items[i]))==typeid(enemy))
        {
            scene()->removeItem(coliding_items[i]);
            scene()->removeItem(this);
            delete coliding_items[i];
            delete this;
            return;
        }
    }

    this->setPos(x(),y()-5);
    if(y()+75 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }

}







