#include "enemy.h"
#include "player.h"
#include "healthandscore.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <iostream>



enemy::enemy()
{
    //Creating enemy
    QPixmap pixmap2("/Users/mac/ChickenInvaders/ChickenInvaders/BigChicken.png");
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

void enemy::move()
{
    this->setPos(x(),y()+5);
    if (y()+75 > 600)
    {
        scene()->removeItem(this); //remove enemy when it reaches bottom
        delete this;
        if(healthValue>0)
        {
        health->setPlainText("Health: " + QString::number(--healthValue)); //update health
        }
        else if(healthValue==0)
        {

            --healthValue;
            QMessageBox *msg=new QMessageBox;
            msg->setText("Game Over, Your Score is "+ QString::number(scoreValue));
            //std::cout << scoreValue << std::endl;
            msg->setWindowTitle("You Lost!");
            //msg->setStandardButtons(QMessageBox::Button);
            int ret = msg->exec();
            std::cout << ret;




        }
        else
        {
            QTimer* t1= new QTimer;
            disconnect(t1, SIGNAL(timeout()),this,SLOT (move()));
        }



    }
}

