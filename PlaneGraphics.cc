#include "ObjectManager.h"

PlaneGraphic::PlaneGraphic(size_t id, QGraphicsScene* scene,  QObject* parent=0) : QObject(parent), scene(scene), id(id){
    if(id == 0){
       pixmaps.insert(Normal, QPixmap("plane3.png"));
       pixmaps.insert(Mirror, QPixmap("plane3m.png"));
       pixmaps.insert(Top, QPixmap("planetop.png"));
       pixmaps.insert(Bottom, QPixmap("planebottom.png"));
       pixmaps.insert(Crash1, QPixmap("crash1.png"));
       pixmaps.insert(Crash2, QPixmap("crash2.png"));
       kone = scene->addPixmap(pixmaps[Normal]);
       kone->setTransformOriginPoint(15,8);

    }
    if(id == 1){
       pixmaps.insert(Normal, QPixmap("plane2.png"));
       pixmaps.insert(Mirror, QPixmap("plane2m.png"));
       pixmaps.insert(Top, QPixmap("plane2top.png"));
       pixmaps.insert(Bottom, QPixmap("plane2bottom.png"));
       pixmaps.insert(Crash1, QPixmap("crash21.png"));
       pixmaps.insert(Crash2, QPixmap("crash22.png"));
       kone = scene->addPixmap(pixmaps[Normal]);
       kone->setTransformOriginPoint(15,8);

    }
}


void PlaneGraphic::update(void){
 Plane* tmp = ObjectManager::Instance()->GetObjectFromID(id);
 size_t state = tmp->getState();
 switch (state){
 case 5:
     kone->setPixmap(pixmaps[Crash1]);

     break;
 case 4:
     kone->setPixmap(pixmaps[Crash2]);

    break;

 case 3:
     kone->setPixmap(pixmaps[Bottom]);
     kone->setPos(tmp->getXPos(),tmp->getYPos());
     kone->setRotation((tmp->getAngle()/(2*3.14))*360);
    break;
 case 2:
     kone->setPixmap(pixmaps[Top]);
     kone->setPos(tmp->getXPos(),tmp->getYPos());
     kone->setRotation((tmp->getAngle()/(2*3.14))*360);
    break;
 case 1:
     kone->setPixmap(pixmaps[Mirror]);
     kone->setPos(tmp->getXPos(),tmp->getYPos());
     kone->setRotation((tmp->getAngle()/(2*3.14))*360);
     break;

 case 0:
     kone->setPixmap(pixmaps[Normal]);
     kone->setPos(tmp->getXPos(),tmp->getYPos());
     kone->setRotation((tmp->getAngle()/(2*3.14))*360);
     break;
 }

}

QGraphicsPixmapItem* PlaneGraphic::getPicture(){
 return kone;
}
