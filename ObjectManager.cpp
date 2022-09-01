#include "ObjectManager.h"

std::map<size_t, Plane*> ObjectManager::objects;

std::map<size_t, Projectile*> ObjectManager::projectiles;

std::map<size_t, Gun*> ObjectManager::guns;

std::map<size_t, soldier*> ObjectManager::soldiers;

std::map<size_t, Graphics*> ObjectManager::graphics;


void ObjectManager::RegisterObject(Plane* obj, size_t id){
    objects[id] = obj;
}

Plane* ObjectManager::GetObjectFromID(size_t id){
    return objects[id];
}

void ObjectManager::ReleaseObjects(){

        for(size_t i = 0; i < objects.size(); i++){
            delete objects[i];
        }
        for(size_t i = 0; i < soldiers.size(); i++){
            delete soldiers[i];
        }
        for(size_t i = 0; i < guns.size(); i++){
            delete guns[i];
        }
        for(size_t i = 0; i < projectiles.size(); i++){
            delete projectiles[i];
        }



        objects.clear();
        soldiers.clear();
        guns.clear();
        projectiles.clear();

        graphics[0]->ReleaseGraphics();
        delete graphics[0];
}

Projectile* ObjectManager::GetProjectileFromID(size_t id){
    return projectiles[id];
}

Gun* ObjectManager::GetGunFromID(size_t id){
    return guns[id];
}

soldier* ObjectManager::GetSoldierFromID(size_t id){
    return soldiers[id];
}

void ObjectManager::Update(){
        std::map<size_t, Plane*>::iterator iter1 = objects.begin();
        while(iter1 != objects.end()){
                if(iter1->second != NULL){
                        iter1->second->update();
                }
        iter1++;
        }
        std::map<size_t, Projectile*>::iterator iter2 = projectiles.begin();
        while(iter2 != projectiles.end()){
                if(iter2->second != NULL){
                        iter2->second->update();
                }
        iter2++;
        }
        std::map<size_t, Gun*>::iterator iter3 = guns.begin();
        while(iter3 != guns.end()){
                if(iter3->second != NULL){
                        iter3->second->fire();
                        iter3->second->dropBomb();
                        iter3->second->fireMissile();
                }
        iter3++;
        }
        std::map<size_t, soldier*>::iterator iter10 = soldiers.begin();
        while(iter10 != soldiers.end() ){
                if(iter10->second != NULL){
                        iter10->second->update();
                       }
        iter10++;
        }

}


void ObjectManager::RegisterProjectile(Projectile* obj, size_t id){
    projectiles[id] = obj;
}

void ObjectManager::RegisterGun(Gun* gun, size_t id){
    guns[id] = gun;
}

void ObjectManager::RegisterSoldier(soldier* obj, size_t id){
   this->soldiers[id] = obj;
}


void ObjectManager::RegisterGraphics(Graphics* g){
    graphics[0] = g;
}

void ObjectManager::RemoveProjectile(size_t id){
    delete projectiles[id];
    projectiles.erase(id);
}

void ObjectManager::RemoveSoldier(size_t id){
    delete soldiers[id];
    soldiers.erase(id);
}

Graphics* ObjectManager::GetGraphics(){
    return graphics[0];
}


