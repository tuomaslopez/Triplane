#include "MyWindow.h"
#include "Graphics.h"


MyWindow::MyWindow(void){actions.insert( Qt::Key_W, Accel0 );
               actions.insert( Qt::Key_A, Left0);
               actions.insert( Qt::Key_D, Right0 );
               actions.insert( Qt::Key_S, Slow0 );
               actions.insert( Qt::Key_E, Roll0 );
               actions.insert(Qt::Key_R, Shoot0);
               actions.insert(Qt::Key_Space, Drop0);
               actions.insert(Qt::Key_C, Missile0);
               actions.insert( Qt::Key_8, Accel1 );
               actions.insert( Qt::Key_6, Left1);
               actions.insert( Qt::Key_4, Right1 );
               actions.insert( Qt::Key_5, Slow1 );
               actions.insert( Qt::Key_7, Roll1 );
               actions.insert(Qt::Key_0, Shoot1);
               actions.insert(Qt::Key_Enter, Drop1);
               actions.insert(Qt::Key_1, Missile1);
               actions.insert( Qt::Key_Escape, Escape );

              }

void MyWindow::keyPressEvent(QKeyEvent *event){
    if ( event->isAutoRepeat() || !actions.contains( event->key() ) )
    {
        event->ignore();
        return;
    }

    Action a = actions[event->key()];
    Plane* tmp0 = ObjectManager::Instance()->GetObjectFromID(0);
    Plane* tmp1 = ObjectManager::Instance()->GetObjectFromID(1);
    Gun* gun0 = ObjectManager::Instance()->GetGunFromID(0);
    Gun* gun1 = ObjectManager::Instance()->GetGunFromID(1);
    switch ( a )
    {
        case Accel0:
            tmp0->ifaccel(true);
            break;

        case Left0:
            tmp0->ifrotateleft(true);
            break;

        case Right0:
            tmp0->ifrotateright(true);
            break;
        case Slow0:
            tmp0->ifslow(true);
            break;
        case Shoot0:
            gun0->ifshoot(true);
            break;
        case Drop0:
            gun0->ifdrop(true);
            break;
        case Missile0:
            gun0->ifmissile(true);
            break;
        case Accel1:
            tmp1->ifaccel(true);
            break;

        case Left1:
            tmp1->ifrotateleft(true);
            break;

        case Right1:
            tmp1->ifrotateright(true);
            break;
        case Slow1:
            tmp1->ifslow(true);
            break;
        case Shoot1:
            gun1->ifshoot(true);
            break;
        case Drop1:
            gun1->ifdrop(true);
            break;
        case Missile1:
            gun1->ifmissile(true);
            break;

        default:
            event->ignore();
             return;
    }
    event->accept();
}
void MyWindow::keyReleaseEvent(QKeyEvent *event){
    if ( event->isAutoRepeat() || !actions.contains( event->key() ) )
    {
        event->ignore();
        return;
    }

    Action a = actions[ event->key()];
    Plane* tmp0 = ObjectManager::Instance()->GetObjectFromID(0);
    Plane* tmp1 = ObjectManager::Instance()->GetObjectFromID(1);
    Gun* gun0 = ObjectManager::Instance()->GetGunFromID(0);
    Gun* gun1 = ObjectManager::Instance()->GetGunFromID(1);
    switch ( a )
    {
        case Accel0:
            tmp0->ifaccel(false);
            break;

        case Left0:
            tmp0->ifrotateleft(false);
            break;

        case Right0:
            tmp0->ifrotateright(false);
            break;
        case Slow0:
            tmp0->ifslow(false);
            break;
        case Roll0:
            tmp0->mirror();
            break;
        case Shoot0:
            gun0->ifshoot(false);
            break;
        case Drop0:
            gun0->ifdrop(false);
            break;
        case Missile0:
            gun0->ifmissile(false);
            break;
        case Accel1:
            tmp1->ifaccel(false);
            break;

        case Left1:
            tmp1->ifrotateleft(false);
            break;

        case Right1:
            tmp1->ifrotateright(false);
            break;
        case Slow1:
            tmp1->ifslow(false);
            break;
        case Roll1:
            tmp1->mirror();
            break;
        case Shoot1:
            gun1->ifshoot(false);
            break;
        case Drop1:
            gun1->ifdrop(false);
            break;
        case Missile1:
            gun1->ifmissile(false);
            break;
        case Escape:
            ObjectManager::Instance()->ReleaseObjects();
            qApp->quit();

            break;
        default:
            event->ignore();
            return;
}

event->accept();
}
