#include "Missile.h"
#include "ObjectManager.h"

Missile::Missile(Plane* owner): Projectile(owner) {
    time.start(), nextId++, v = 6, angle = owner->getAngle(), damage = 5, x += 29 * cos(angle), y += 29 * sin(angle), type = 3;
    if(owner->getID() == 0)
        enemy = ObjectManager::Instance()->GetObjectFromID(1);
    else
        enemy = ObjectManager::Instance()->GetObjectFromID(0);
}

void Missile::update(){
    // Takes the angle between missile and target and compares it to the angle of the missile and based on that it makes a desion to increase or decrease the angle.
    double SuoraKulma = atan2( (enemy->getYPos() - y), (enemy->getXPos() -x ) );
      if(angle < -(PI/2) || angle > (PI/2)){

        if((angle < 0) && (SuoraKulma > 0)){
            angle += 2*PI;

        }

       else if(angle > 0 && SuoraKulma < 0){
           SuoraKulma += 2*PI;
        }
      }

       if(angle < SuoraKulma){
           angle += 0.01;
       }
       else{
           angle -= 0.01 ;
       }

       x += v*cos(angle);
       y += v*sin(angle);
}
