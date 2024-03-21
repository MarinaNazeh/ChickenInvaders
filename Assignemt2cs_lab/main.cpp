
#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "player.h"

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

    QGraphicsRectItem* rect1 = new QGraphicsRectItem () ;
    rect1->setRect (0, 0,100, 100);

    QPixmap pixmap1("chicken.PNG");
    pixmap1 = pixmap1.scaledToWidth(50);
    pixmap1 = pixmap1.scaledToHeight(50);
    QGraphicsPixmapItem * image1 = new QGraphicsPixmapItem;
    image1->setPixmap(pixmap1);
    image1->setPos(30, 400);
    scene->addItem(rect1);
    scene->addItem(image1);

    image1->setFlag(QGraphicsItem::ItemIsFocusable);
    image1->setFocus();

    view->setScene(scene);
    view->show();
    return a.exec();
}
