#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

enemy::enemy()
{
    //Creating enemy
    QPixmap pixmap2("C:\\Users\\mahin\\Desktop\\Uni\\Spring 2024\\CS 2 Lab\\Assignments\\Assignment 2\\Assignment 2\\ChickenInvaders\\ChickenInvaders\\BigChicken.png");
    pixmap2 = pixmap2.scaledToWidth(75);
    pixmap2 = pixmap2.scaledToHeight(75);
    this->setPixmap(pixmap2);

   //setting position of enemy within view dimensions
    int random_number = rand() % 700;
    this->setPos(random_number,0);

    //moving enemy downwards automatically every 100 milliseconds
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(100);
    qDebug()<<"inside constructor";
}

void enemy:: move()
{
    this->setPos(x(),y()+5);
}

