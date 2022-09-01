#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <map>
#include <iostream>

#include "Gun.h"
#include "Plane.h"
#include "Projectile.h"
#include "Soldier.h"
#include "Graphics.h"

//OBJECTMANAGER HANDLES ALL LOGIC OBJECTS UPDATING AND RELEASING

class ObjectManager
{

public:

static ObjectManager* Instance(){ //Static accessor function
        static ObjectManager objman;
        return &objman;
}

void RegisterObject(Plane* obj, size_t id); //Register Planes

Plane* GetObjectFromID(size_t id); //Getter for planes

Gun* GetGunFromID(size_t id); //Getter for Guns

soldier* GetSoldierFromID(size_t id); //Getter for Soldiers

Projectile* GetProjectileFromID(size_t id); //Getter for projectiles

Graphics* GetGraphics();

void RegisterGun(Gun* gun, size_t id); //Register Guns

void RegisterSoldier(soldier* obj, size_t id); //Register Soldier

void RegisterGraphics(Graphics* g);

void RemoveProjectile(size_t id); //Remove Projectile

void RemoveSoldier(size_t id); //Remove Soldier

void ReleaseObjects(); //Release all objects stored

void Update(); //Calls update on all objects stored

void RegisterProjectile(Projectile* obj, size_t id); //Register Projectiles



private:
ObjectManager() {}
ObjectManager(const ObjectManager&);
ObjectManager& operator=(const ObjectManager&);
static std::map<size_t, Plane*> objects;
static std::map<size_t, Projectile*> projectiles;
static std::map<size_t, Gun*> guns;
static std::map<size_t, soldier*> soldiers;
static std::map<size_t, Graphics*> graphics;
};

#endif // OBJECTMANAGER_H
