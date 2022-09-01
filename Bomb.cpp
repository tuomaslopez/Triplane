#include "Bomb.h"

Bomb::Bomb(Plane *owner) : Projectile(owner)
{nextId++, time.start(), v = 2, damage = 5, y += 12, type = 2;}

void Bomb::update(){
    double vx = owner->getVelocity() * cos(owner->getAngle());
    x += vx;
    y += v;
}
