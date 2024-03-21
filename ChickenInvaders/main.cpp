

#include <QApplication>

#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create scene
    QGraphicsScene * scene = new QGraphicsScene () ;
    scene->setSceneRect(0, 0, 800, 600);


    // create view
    QGraphicsView * view = new QGraphicsView (scene);
    view->setFixedSize(800, 600);


    // disable scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create the player
    Player * player = new Player();
    // QPixmap pixmap1("chicken.PNG");
    // pixmap1 = pixmap1.scaledToWidth(50);
    // pixmap1 = pixmap1.scaledToHeight(50);
    // QGraphicsPixmapItem * image1 = new QGraphicsPixmapItem;
    // image1->setPixmap(pixmap1);
    // image1->setPos(30, 400);

    // scene->addItem(image1);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    view->setScene(scene);
    scene->addItem(player);
    view->show();

    return a.exec();
}
