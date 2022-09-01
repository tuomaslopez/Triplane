#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <cmath>
#include <QTime>

//CLASS FOR PLANES LOGIC. UPDATES PLANE

#define GRAVITY -1
#define ILMANVASTUS 0.005
#define CRASHANGLE 0.5
#define MAXSPEED 3.5
#define CRASHSPEED 0.5
#define WIDTH 800
#define HEIGHT 600
#define TURNANGLE 0.02
#define ACCELERATION 0.1
#define BRAKES 0.03
#define PI 3.1415926


class Plane
{
public:
    Plane(size_t id, const int xspawn, const int yspawn, const double spawnangle, const bool spawnMIRROR);

    void update(); //UPDATE FUNCTION, INCLUDES PLANES PHYSICS

    //GETTERS FOR VARIABLES
    double getXPos();

    double getYPos();

    double getAngle();

    double getVelocity();

    //ACTIONS
    void accelrate();

    void up();

    void down();

    void slow();

    //CHANGERS FOR PLANES ACTIONS
    void ifaccel(bool a);

    void ifrotateleft(bool rl);

    void ifrotateright(bool rr);

    void ifslow(bool sl);

    void mirror();

    //PLANE CRASH FUNCTION, CALLED WHEN PLANE IS DESTROYED
    void planeCrash();

    //PLANE TAKE DAMAGE FUNCTION
    void takeDamage(size_t damage);

    //TIME ELAPSED FROM LAST CRASH
    int getCrashTime();

    //GETTER FOR PLANES STATE FOR GRAPHICS DRAWING
    size_t getState(void);

    size_t getID();

    size_t getDeaths();

private:
    size_t id;
    const int xspawn;
    const int yspawn;
    double x;
    double y;
    double v;
    double angle;
    double crangle;
    const double spawnangle;
    int hp;
    size_t deaths;
    const bool spawnMIRROR;
    bool ACCELERATE;
    bool ROTATELEFT;
    bool ROTATERIGHT;
    bool MIRROR;
    bool SLOW;
    QTime mirrorTime;
    QTime crashTime;
};

#endif // PLANE_H
