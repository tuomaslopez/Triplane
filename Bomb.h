#ifndef BOMB_H
#define BOMB_H

#include "Projectile.h"

//Bomb falls down and explodes when it hits something

class Bomb : public Projectile{
public:

    Bomb(Plane* owner);

    void update();

};

#endif // BOMB_H
