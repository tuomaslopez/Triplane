#ifndef BULLET_HH
#define BULLET_HH

#include "Projectile.h"

//Bullet flies straight and causes damage when it hits something

class bullet : public Projectile{
public:

    bullet(Plane* owner); //Constructor for bullets shot by players

    bullet(size_t damage, double vx, double vy, double x, double y); //Constructor for bullets shot by soldiers

    void update();

};


#endif // BULLET_HH
