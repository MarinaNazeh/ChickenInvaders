#ifndef BULLET_H
#define BULLET_H
#include "player.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

class bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bullet();

public slots:
    void move();


};

#endif // BULLET_H
