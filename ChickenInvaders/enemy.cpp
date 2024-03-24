#include "enemy.h"
#include "player.h"
#include "healthandscore.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QPushButton>
#include <QCoreApplication>
#include <iostream>

enemy::enemy()
{

    //Creating enemy
    QPixmap pixmap2(":/BigChicken.png");
    pixmap2 = pixmap2.scaledToWidth(75);
    pixmap2 = pixmap2.scaledToHeight(75);
    this->setPixmap(pixmap2);

   //setting position of enemy within view dimensions
    int random_number = rand() % 700;
    this->setPos(random_number,0);

    //moving enemy downwards automatically every 100 milliseconds
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(100);
    qDebug()<<"inside constructor";
}

void enemy::move()
{

    if (healthValue>=1) //to stop enemies from moving further when game is over
    {
        this->setPos(x(),y()+5);
    }

    if (y()+75 > 600) //when enemy reaches the bottom
    {
        scene()->removeItem(this); //remove enemy
        delete this;

        health->setPlainText("Health: " + QString::number(--healthValue)); //update health

        if (healthValue<=0) //it is 0 instead of 1 since the value was already updated up
        {
            //displaying the message box when game is over
            QMessageBox *msg = new QMessageBox;
            msg->setText("Game Over, Your Score is " + QString::number(scoreValue));
            msg->setWindowTitle("You Lost!");
            QPushButton * exit = new QPushButton("Exit Game"); //creating a button to exit game
            msg->addButton(exit, QMessageBox::AcceptRole); //adding button to the message box
            int ret = msg->exec();
            std::cout << ret;

            if (msg->clickedButton() == exit)
            {
                QCoreApplication::quit(); //to quit the game
            }
        }
    }
}

