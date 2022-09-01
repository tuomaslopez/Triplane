#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QtGui>


#include "PlaneGraphics.h"
#include <QGraphicsItem>

//GRAPHICS MAIN CLASS, HANDLES ALL GRAPHICS AND THEIR UPDATING


class Graphics : public QObject
{
public:

    Graphics(QGraphicsScene* scene,  QObject* parent);

    void update();

    void collisionDetection(); //collisionDetection detects if GraphicItems (=planes, projectiles and soldiers) collide

    QString getDeaths(); //getDeaths returns QString which tells how many times players have died in the game

    void ReleaseGraphics();

private:

    QGraphicsScene* scene;
    QObject* parent;
    PlaneGraphic* plane1;
    PlaneGraphic* plane2;
    QPixmap* bomb;
    QPixmap* missile;
    QPixmap* sotilas;
    QGraphicsPixmapItem* taustakuva;
    std::map<size_t, QGraphicsItem*> projectileImages;
    std::map<size_t, QGraphicsItem*> soldierImages;
};

#endif // GRAPHICS_H
