#ifndef GUN_H
#define GUN_H

#include "Projectile.h"

//Gun is class that is called when player fires weapon in the game. Creates projectiles.

class Gun
{
public:

    Gun(Plane* owner, double rateOfFire); //Constructor, takes plane that owns gun and guns rate of fire as parameters.

    void fire(); //Creates bullets

    void dropBomb(); //Creates bombs

    void fireMissile(); //Creates missiles

    void ifshoot(bool a); //True when fire bullet key is pushed

    void ifdrop(bool a); //True when drop bomb key is pushed

    void ifmissile(bool a); //True when fire missile key is pushed

private:
        Plane* owner;
        double rateOfFire;
        QTime shootTime;
        QTime dropTime;
        QTime missileTime;
        bool SHOOT;
        bool DROP;
        bool MISSILE;
};

#endif // GUN_H
