#include "ObjectManager.h"
#include <sstream>

static bool haveSoldiersBeingDrawn = false;

Graphics::Graphics(QGraphicsScene* scene,  QObject* parent=0) : QObject(parent), scene(scene){
    QPixmap tausta("taustakuva2.png");
    bomb = new QPixmap("bomb.png");
    missile = new QPixmap("missile.png");
    taustakuva = scene->addPixmap(tausta);
    plane1 = new PlaneGraphic(0, scene, parent);
    plane2 = new PlaneGraphic(1, scene, parent);
    sotilas = new QPixmap("sotilas.png");
}

void Graphics::update(){
    plane1->update();
    plane2->update();
    Projectile* tmp1;
    for(size_t i = 0; i < Projectile::getNextId(); i++){
        tmp1 = ObjectManager::Instance()->GetProjectileFromID(i);
        if(tmp1 != NULL){
            if(!projectileImages[i] && tmp1->getType() == 1){
                projectileImages[i] = scene->addEllipse(0, 0, 2, 2);
            }
            else if(!projectileImages[i] && tmp1->getType() == 2){
                projectileImages[i] = scene->addPixmap(*bomb);
            }
            else if(!projectileImages[i] && tmp1->getType() == 3){
                projectileImages[i] = scene->addPixmap(*missile);
            }
            else{
                projectileImages[i]->setPos(tmp1->getXPos(), tmp1->getYPos());
            }
            if(tmp1->getXPos() > 800){
                tmp1->setX(0);
                tmp1->setY(tmp1->getYPos() + 200);
            }
            else if(tmp1->getXPos() < 0){
                tmp1->setX(800);
                tmp1->setY(tmp1->getYPos() - 200);
            }
            if(tmp1->getTime() > 10000){
                ObjectManager::Instance()->RemoveProjectile(i);
                delete projectileImages[i];
                projectileImages.erase(i);
            }
            if((tmp1->getYPos() > 180 && tmp1->getYPos() < 200) || (tmp1->getYPos() > 380 && tmp1->getYPos() < 400) || (tmp1->getYPos() < 0 || tmp1->getYPos() > 580)){
                ObjectManager::Instance()->RemoveProjectile(i);
                delete projectileImages[i];
                projectileImages.erase(i);
            }
        }
        tmp1 = NULL;
    }
    soldier* temp20;
    if(haveSoldiersBeingDrawn == false){
        for(size_t i = 0; i < 10; i++){
            temp20 = ObjectManager::Instance()->GetSoldierFromID(i);
            if(temp20 != NULL){
                soldierImages[i] = scene->addPixmap(*sotilas);
            }
        }
        haveSoldiersBeingDrawn = true;
    }

    for(size_t i = 0; i < 10; i++){
        temp20 = ObjectManager::Instance()->GetSoldierFromID(i);
        if(temp20 != NULL){
            soldierImages[i]->setPos(temp20->getXPos(), temp20->getYPos());
        }
    }
}

//collisionDetection detects if GraphicItems (=planes, projectiles and soldiers) collide
void Graphics::collisionDetection(){
    Plane* tmp1 = ObjectManager::Instance()->GetObjectFromID(0);
    if(plane1->getPicture()->collidesWithItem(plane2->getPicture())){
        if((tmp1->getState() != 4) && (tmp1->getState() != 5)){
            ObjectManager::Instance()->GetObjectFromID(0)->planeCrash();
            ObjectManager::Instance()->GetObjectFromID(1)->planeCrash();
        }
    }
    for(size_t i = 0; i < Projectile::getNextId(); i++){
        if(plane1->getPicture()->collidesWithItem(projectileImages[i])){
            ObjectManager::Instance()->GetObjectFromID(0)->takeDamage(ObjectManager::Instance()->GetProjectileFromID(i)->getDamage());
            ObjectManager::Instance()->RemoveProjectile(i);
            delete projectileImages[i];
            projectileImages.erase(i);
        }
        else if(plane2->getPicture()->collidesWithItem(projectileImages[i])){
            ObjectManager::Instance()->GetObjectFromID(1)->takeDamage(ObjectManager::Instance()->GetProjectileFromID(i)->getDamage());
            ObjectManager::Instance()->RemoveProjectile(i);
            delete projectileImages[i];
            projectileImages.erase(i);
        }
    }
    for(size_t i = 0; i < 10; i++){
        if(plane1->getPicture()->collidesWithItem(soldierImages[i])){
            ObjectManager::Instance()->GetObjectFromID(0)->takeDamage(1);
            ObjectManager::Instance()->RemoveSoldier(i);
            delete soldierImages[i];
            soldierImages.erase(i);
        }
        else if(plane2->getPicture()->collidesWithItem(soldierImages[i])){
            ObjectManager::Instance()->GetObjectFromID(1)->takeDamage(1);
            ObjectManager::Instance()->RemoveSoldier(i);
            delete soldierImages[i];
            soldierImages.erase(i);
        }
    }
    for(size_t i = 0; i < Projectile::getNextId(); i++){
        QGraphicsItem* tmp = projectileImages[i];
        for(size_t j = 0 ; j < 10 ; j++){
            QGraphicsItem* sotilas = soldierImages[j];
            if((sotilas != NULL) && (tmp != NULL) && (sotilas->collidesWithItem(tmp))){
                ObjectManager::Instance()->RemoveSoldier(j);
                ObjectManager::Instance()->RemoveProjectile(i);
                delete tmp;
                tmp = NULL;
                projectileImages.erase(i);
                delete sotilas;
                sotilas = NULL;
                soldierImages.erase(j);
            }
        }
    }
}

//getDeaths returns QString which tells how many times players have died in the game
QString Graphics::getDeaths(){
    std::stringstream ss (std::stringstream::in | std::stringstream::out);
    size_t p1deaths = ObjectManager::Instance()->GetObjectFromID(0)->getDeaths();
    size_t p2deaths = ObjectManager::Instance()->GetObjectFromID(1)->getDeaths();
    ss << "Player 1 deaths: " << p1deaths << "     Player 2 deaths: " << p2deaths;
    std::string stdresult = ss.str();
    QString result = QString::fromStdString(stdresult);
    return result;
}

//endGame returns QString which tells who has won the game. Takes number of the player who has won as parameter. Deletes also images made in constructor
void Graphics::ReleaseGraphics(){
    delete plane1;
    delete plane2;
    delete bomb;
    delete sotilas;
    delete missile;

}
