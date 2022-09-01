#include "Plane.h"

Plane::Plane(size_t id, const int xspawn, const int yspawn, const double spawnangle = 0, const bool spawnMIRROR = false) :id(id), xspawn(xspawn), yspawn(yspawn), spawnangle(spawnangle), spawnMIRROR(spawnMIRROR), hp(5), deaths(0){
    ACCELERATE = false;
    ROTATELEFT = false;
    ROTATERIGHT = false;
    SLOW = false;
    MIRROR = spawnMIRROR;
    angle = spawnangle;
    x = xspawn;
    y = yspawn;
    v  = 0;


}
void Plane::update(){

    // KONEEN KULMA EI SAA OLLA YLI 2pi
    if(angle > 2*PI){
        angle -= 2*PI;
    }
    if(angle < -2*PI){
        angle += 2*PI;
    }
    // JOS KONE ON PEILKUVANA SEN LASKEUTUMISKULME KÄÄNTYY -180ASTETTA
    if(MIRROR && spawnMIRROR){
        crangle = angle - PI;
    }
    else if(MIRROR && !spawnMIRROR){
        crangle = angle + PI;
    }
    else{
        crangle = angle;
    }

    //ENSIMMÄISEN TASON LASKEUTUMINEN
    if(y > 165 && y < 180){
        //planecrash

        if(v*sin(angle) > CRASHSPEED || fabs(crangle) > CRASHANGLE){
            this->planeCrash();

        }

        else{y = 165;
        }
    }
    //TOISEN TASON LASKEUTUMINEN
    else if(y > 365 && y < 380){
        //planecrash
        if(v*sin(angle) > CRASHSPEED || fabs(crangle) > CRASHANGLE){
            this->planeCrash();

        }

        else{y = 365;
        }
    }
    //ALIMMAN TASON LASKEUTUMINEN
    else if(y > 565 && y < 610){
        //planecrash
        if(v*sin(angle) > CRASHSPEED || fabs(crangle) > CRASHANGLE){

            this->planeCrash();

        }

        else{y = 565;
        }

    }
    //TÖRMÄYS KATTOON KESKITASOLLA
    else if(y > 180 && y < 210){
        this->planeCrash();

    }
    //TÖRMÄYS KATTOON ALIMMALLA TASOLLA
    else if(y > 380 && y < 410){
        this->planeCrash();
    }


    //SIIRROT TASOSTA TOISEEN
    if(x > WIDTH){
        x = 0;
        y += 200;
    }


    else if(x < 0){
        x = 800;
        y -= 200;
    }
    //TARKISTUS ONKO KONE PELIALUEELLA(TÖRMÄYS YLIMMÄN TASON KATTOON)
    if(y <0 || y > HEIGHT){
        this->planeCrash();

    }
    //
    x += v*cos(angle);
    y += v*sin(angle) - GRAVITY;


    if( v > 0){
        v -= ILMANVASTUS;
    }

    if(ACCELERATE){
        this->accelrate();

    }
    if(ROTATELEFT){
        if(MIRROR){
            this->up();
        }
        else{
            this->down();
        }
    }
    if(ROTATERIGHT){
        if(MIRROR){
            this->down();
        }
        else{
            this->up();
        }

    }
    //std::cout << angle << std::endl;
    //jarrut toimivat vain kun kone on maassa
    if(SLOW && ((y >= 165 && y <= 200)  || (y >= 365 && y <= 400) || (y >= 565 && y <= 600))){
        this->slow();
    }
}

double Plane::getXPos(){

    return x;
}
double Plane::getYPos(){

    return y;
}

double Plane::getAngle(){
    return angle;
}

double Plane::getVelocity(){
    return v;
}

void Plane::accelrate(){

        if(v < MAXSPEED){
            v += ACCELERATION;
        }

}

void Plane::up(){

    angle += TURNANGLE*v;

}

void Plane::down(){

    angle-= TURNANGLE*v;
}
void Plane::slow(){
    if(v > 0){
        v -= BRAKES;

    }
    if(v < 0){
        v = 0;
    }
}

void Plane::ifaccel(bool a){
    ACCELERATE = a;

}
void Plane::ifrotateleft(bool rl){
    ROTATELEFT = rl;
}

void Plane::ifrotateright(bool rr){
    ROTATERIGHT = rr;
}

void Plane::ifslow(bool sl){
    SLOW = sl;
}
void Plane::mirror(){
    if(MIRROR){
        MIRROR = false;
    }
    else{
        MIRROR = true;
    }
    mirrorTime.start();
}
void Plane::planeCrash(){
    x = xspawn;
    y = yspawn;
    v = 0;
    hp = 5;
    deaths++;
    angle = spawnangle;
    MIRROR = spawnMIRROR;
    crashTime.start();
}

int Plane::getCrashTime(){
    return crashTime.elapsed();
}

size_t Plane::getState(void){
    if(crashTime.elapsed() < 150){
        return 5;
    }
    else if(crashTime.elapsed() < 300){
        return 4;
    }
    else if((mirrorTime.elapsed() < 200) && MIRROR){
        return 3;
    }
    else if((mirrorTime.elapsed() < 200) && !MIRROR){
        return 2;
    }
    else{
        if(MIRROR){
           return 1;
        }
        else{
            return 0;
        }
    }
}

size_t Plane::getID(){
    return id;
}

void Plane::takeDamage(size_t damage){
    hp -= damage;
    if(hp < 1)
        this->planeCrash();
}

size_t Plane::getDeaths(){
    return deaths;
}
