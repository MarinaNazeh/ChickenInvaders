#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include "player.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create scene
    QGraphicsScene scene;;
    scene.setSceneRect(0, 0, 800, 600);

    // create view
    QGraphicsView view;
    view.setFixedSize(800, 600);
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create the player
    Player * player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene.addItem(player);

    // create enemies
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);


    view.show();
    return a.exec();
}
