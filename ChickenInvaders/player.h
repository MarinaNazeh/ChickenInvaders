#ifndef PLAYER_H
#define PLAYER_H
#include <QDialog>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>

class Player: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT

public:
    Player();
    void keyPressEvent(QKeyEvent * event);

public slots:
    void createEnemy();
};

#endif // PLAYER_H
