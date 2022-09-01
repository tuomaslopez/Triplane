#ifndef WORLD_H
#define WORLD_H


#include <iostream>
#include <sstream>
#include <vector>
#include <QtGui>
#include "ObjectManager.h"

//CLASS FOR THE GAME WORLD

class World : public QObject
{
    Q_OBJECT
public:
    World(QGraphicsScene* scene, QObject* parent);

    void start();

public slots:
    void updateWorld(); //UPDATES WORLD, CALLS UPDATE TO ALL AT 60 HZ

private:
    QGraphicsTextItem* scoreBoard;
    Graphics* WorldGraphics;
    QGraphicsScene* scene;
    QTimer* timer;
};



#endif // WORLD_H
