#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Plane.h"

//Abstract class which is inherited by Bomb, Bullet and Missile classes. Represents projectiles that are fired in the game.

class Projectile{
public:
    Projectile(Plane* owner); //Constructor, takes plane which fired this projectile as parameter

    Projectile(size_t damage, double vx, double vy, double x, double y); //Alternative constructor, needed for bullets which are shot by soldiers, not planes

    virtual ~Projectile() {} //Virtual destructor

    double getXPos(); //Returns horizontal coordinate of the projectile

    double getYPos(); //Returns vertical coordinate of the projectile

    void setX(double); //Sets horizontal coordinate of the projectile

    void setY(double); //Sets vertical coordinate of the projectile

    size_t getDamage(); //Returns damage of the projectile

    virtual void update() = 0; //Virtual function, implemented by inheriting classes. Updates projectiles position and velocity

    static size_t getNextId(); //Return next free id for new projectile

    double getTime(); //Return how long ago projectile was created

    size_t getType(); //Returns type of the projectile: bullet = 1, bomb = 2, missile = 3

protected:
    double x;
    double y;
    double v;
    double angle;
    double damage;
    Plane* owner;
    static size_t nextId;
    QTime time;
    size_t type;

};

#endif // PROJECTILE_H
