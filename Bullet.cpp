#include "Bullet.h"

bullet::bullet(Plane* owner): Projectile(owner)
{nextId++, time.start(), v = 6, angle = owner->getAngle(), damage = 1, x += 29 * cos(angle), y += 29 * sin(angle), type = 1;}

bullet::bullet(size_t damage, double vx, double vy, double x, double y) : Projectile(damage, vx, vy, x, y)
{nextId++, time.start(), v = 6, x += 29 * cos(angle), y += 29 * sin(angle), type = 1;}

void bullet::update(){
    x += v * cos(angle);
    y += v * sin(angle);
}
