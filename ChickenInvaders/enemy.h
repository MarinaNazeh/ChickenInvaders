#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
class enemy : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT

QTimer * timer = new QTimer();
public:
    enemy();

public slots:
    void move();
};

#endif // ENEMY_H
