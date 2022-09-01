#ifndef SOLDIER_H
#define SOLDIER_H
#include "Gun.h"
#include "QTime"
#include <iostream>

//CLASS FOR SOLDIERS LOGIC

class soldier{
public:

    soldier( bool side , double x, double y, size_t id , double range, QTime lastFired);

    bool getside(); //RETURNS SOLDIERS SIDE

    void setEnemyX(double); //SETS ENEMY X VARIABLE

    void setEnemyY(double); //SETS ENEMY Y VARIABLE

    double getEnemyX(); //GETTER FOR ENEMY X

    double getEnemyY(); //GETTER FOR ENEMY Y

    void setEnemyVelocityX(double); //SETS ENEMY VELOCITY IN X PLANE

    void soldierFire(); //SOLDIERS FIRE FUNCTION

    void update(); //UPDATES SOLDIER

    double getXPos(); //GETS X POS

    double getYPos(); //GETS Y POS

    double getXDistance(double soldierX, double enemyX ); //GET X DISTANCE BETWEEN SOLDIER & ENEMY PLANE

    double getYDistance(double soldierY, double enemyY ); //GET Y DISTANCE BETWEEN SOLDIER & ENEMY PLANE

private:
Gun gun;
bool side;
double x;
double y;
size_t id;
double EnemyX;
double EnemyY;
double EnemyVelocityX;
double range;
QTime lastFired;
double initialX;
bool direction;

};

#endif // SOLDIER_H


