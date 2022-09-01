#ifndef MISSILE_H
#define MISSILE_H

#include "Projectile.h"

//Missile follows enemy plane and explodes when it hits something

class Missile : public Projectile{
public:

    Missile(Plane* owner);

    void update();

private:
    Plane* enemy; //Enemy plane which missile follows
};

#endif // MISSILE_H
