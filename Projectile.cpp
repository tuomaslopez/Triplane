#include "Projectile.h"

size_t Projectile::nextId = 0;

Projectile::Projectile(Plane *owner) : x(owner->getXPos()), y(owner->getYPos()), owner(owner){}

Projectile::Projectile(size_t damage, double vx, double vy, double x, double y) : damage(damage), x(x), y(y), angle(atan2(vy, vx)){}

double Projectile::getXPos(){
    return x;
}

double Projectile::getYPos(){
    return y;
}

void Projectile::setX(double newX){
    x = newX;
}

void Projectile::setY(double newY){
    y = newY;
}

size_t Projectile::getDamage(){
    return damage;
}

size_t Projectile::getNextId(){
    return nextId;
}

double Projectile::getTime(){
    return time.elapsed();
}

size_t Projectile::getType(){
    return type;
}
