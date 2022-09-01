#include "World.h"

World::World(QGraphicsScene* scene, QObject* parent=0) : QObject(parent), scene(scene){
    ObjectManager::Instance()->RegisterGraphics(new Graphics(scene, parent));
    scoreBoard = scene->addText(WorldGraphics->getDeaths());
}

void World::start(){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWorld()));
    timer->start(1000/60.f);
 }

void World::updateWorld(){
    ObjectManager::Instance()->Update();
    ObjectManager::Instance()->GetGraphics()->update();
    ObjectManager::Instance()->GetGraphics()->collisionDetection();
    scoreBoard->setPlainText(ObjectManager::Instance()->GetGraphics()->getDeaths());

}
