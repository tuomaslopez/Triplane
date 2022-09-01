#include "Soldier.h"
#include "Gun.h"
#include <math.h>
#include "ObjectManager.h"
#include <map>
#include "Bullet.h"
#include <QTime>
#include <string>
#include <QString>
#include <iostream>

static double onkoAmpunut = 0;
static size_t BulletId= 0;

soldier::soldier( bool side , double x, double y, size_t id , double range, QTime lastFired):
        gun(gun) , side(side), x(x) , y(y), id(id), EnemyX(-50), EnemyY(-50) , EnemyVelocityX(10), range(range) , lastFired(lastFired), initialX(x), direction(true)
{}

bool soldier::getside(){
    return side;
}


void soldier::setEnemyX(double enemy){
    EnemyX = enemy;
}

void soldier::setEnemyY(double enemy){
    EnemyY = enemy;
}

void soldier::setEnemyVelocityX(double vel){
    EnemyVelocityX = vel;
}

double soldier::getEnemyX(){
    return EnemyX ;
}

double soldier::getEnemyY(){
    return EnemyY ;
}

void soldier::soldierFire(){
    QTime nytAika;
    nytAika.start();
    if( range > sqrt( (this->getEnemyX()-1*this->getXPos())*(this->getEnemyX()-1*this->getXPos()) + (this->getEnemyY()-1*this->getYPos())*(this->getEnemyY()-1*this->getYPos() )  ) ){
        double kulma = atan2( (  this->getYDistance(this->getYPos(), this->getEnemyY() )) , ( this->getXDistance(this->getXPos() , this->getEnemyX() ) )    );
        if( onkoAmpunut == 0 && (2000 < lastFired.msecsTo(nytAika) ) && (kulma <= 0.00) ){
            size_t temp =  bullet::getNextId();
            ObjectManager::Instance()->RegisterProjectile(new bullet(1, 200 * cos(kulma), 200 * sin(kulma), this->getXPos(), this->getYPos()  ), temp);
            onkoAmpunut = 0;
            this->lastFired = nytAika;
            return;
        }
    }
}

void soldier::update(){
    if( side == true){
        this->setEnemyX( ObjectManager::Instance()->GetObjectFromID(0)->getXPos()  );
        this->setEnemyY( ObjectManager::Instance()->GetObjectFromID(0)->getYPos()  );
        this->soldierFire();
    }
    if( side == false){
        this->setEnemyX( ObjectManager::Instance()->GetObjectFromID(1)->getXPos()  );
        this->setEnemyY( ObjectManager::Instance()->GetObjectFromID(1)->getYPos()  );
        this->soldierFire();
    }
    if(direction == true)
        x += 40.0*(1.0/60.0);
    if (( direction == true ) && (x- initialX) > 100 ){
        direction = false;
        return;
    }
    if( direction == false)
        x = x-40.0*(1.0/60.0);
    if( (initialX -x ) > 50){
        direction = true;
        return;
    }
}

double soldier::getXPos(){
    return x;
}

double soldier::getYPos(){
    return y;
}

double soldier::getXDistance(double soldierX, double enemyX ){
    if (soldierX < enemyX)
        return( enemyX - soldierX);
    else
        return ( enemyX - soldierX);
}

double soldier::getYDistance(double soldierY, double enemyY ){
    if (soldierY < enemyY)
        return( enemyY - soldierY);
    else
        return ( enemyY - soldierY);
}

