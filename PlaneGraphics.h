#ifndef ANIMATEDITEM_H
#define ANIMATEDITEM_H

#include <QtGui>


#include <cstring>

//CLASS FOR PLANE GRAPHICS, HANDLES PLANES GRAPHIC UPDATE

class PlaneGraphic : public QObject
{
public:

    PlaneGraphic(size_t id, QGraphicsScene* scene,  QObject* parent);
    void update(void);//UPDATE FUNCTION, DRAWS PLANE ACCORDING TO ITS DRAWING STATE
    QGraphicsPixmapItem* getPicture(); //GETTER FOR PICTURE, USED IN COLLISION DETECTION

private:
 enum State{Normal, Mirror, Top, Bottom, Crash1, Crash2};
 QGraphicsScene* scene;
 QMap<State, QPixmap> pixmaps;
 QGraphicsPixmapItem* kone;
 size_t id;


};



#endif // ANIMATEDITEM_H
