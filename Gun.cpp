#include "Gun.h"
#include <QTime>
#include "Bullet.h"
#include "Bomb.h"
#include "Missile.h"
#include "ObjectManager.h"

Gun::Gun(Plane* owner, double rateOfFire): owner(owner), rateOfFire(rateOfFire), SHOOT(false), DROP(false), MISSILE(false)
{shootTime.start(), dropTime.start(), missileTime.start();}

void Gun::fire(){
    if ((shootTime.elapsed() > (0.1 * rateOfFire)) && SHOOT){
        shootTime.restart();
        ObjectManager::Instance()->RegisterProjectile(new bullet(owner), Projectile::getNextId());
    }
}

void Gun::dropBomb(){
    if ((dropTime.elapsed() > (2 * rateOfFire)) && DROP){
        dropTime.restart();
        ObjectManager::Instance()->RegisterProjectile(new Bomb(owner), Projectile::getNextId());
    }
}

void Gun::fireMissile(){
    if((missileTime.elapsed() > (3 * rateOfFire)) && MISSILE){
        missileTime.restart();
        ObjectManager::Instance()->RegisterProjectile(new Missile(owner), Missile::getNextId());
    }
}

void Gun::ifshoot(bool a){
    SHOOT = a;
}

void Gun::ifdrop(bool a){
    DROP = a;
}

void Gun::ifmissile(bool a){
    MISSILE = a;
}
