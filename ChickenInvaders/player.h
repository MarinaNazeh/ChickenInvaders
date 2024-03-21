#ifndef PLAYER_H
#define PLAYER_H
#include <QDialog>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>

class Player: public QObject,public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    Player();
public slots:
    void keyPressEvent(QKeyEvent * event);

};

#endif // PLAYER_H
