#include "World.h"

#include "MyWindow.h"
#include <iostream>
#define PI 3.1415926

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MyWindow window;
    window.grabKeyboard();
    window.setWindowTitle("triplane clone version");
    window.resize(800,600);


    QGraphicsScene scene(&window);
    scene.setSceneRect(0,0,800,600);
    scene.setBackgroundBrush(Qt::blue);


    QGraphicsView view(&scene, &window);

    QTime nytAika;
    nytAika.start();

    ObjectManager::Instance()->RegisterObject(new Plane(0,100,100,0.0, false), 0);
    ObjectManager::Instance()->RegisterObject(new Plane(1,730,500,PI, true), 1);
    ObjectManager::Instance()->RegisterGun(new Gun(ObjectManager::Instance()->GetObjectFromID(0), 1000), 0);
    ObjectManager::Instance()->RegisterGun(new Gun(ObjectManager::Instance()->GetObjectFromID(1), 1000), 1);
    ObjectManager::Instance()->RegisterSoldier( new soldier(false, 200 ,166.5, 1, 1000, nytAika) ,0 );
    ObjectManager::Instance()->RegisterSoldier( new soldier(true, 400, 570, 1, 1000, nytAika) ,1 );
    ObjectManager::Instance()->RegisterSoldier( new soldier(false, 250 ,166.5, 1, 1000, nytAika) ,2 );
    ObjectManager::Instance()->RegisterSoldier( new soldier(true, 350, 570, 1, 1000, nytAika) ,3 );
    ObjectManager::Instance()->RegisterSoldier( new soldier(false, 300 ,166.5, 1, 1000, nytAika) ,4 );
    ObjectManager::Instance()->RegisterSoldier( new soldier(true, 300, 570, 1, 1000, nytAika) ,5 );

    World world(&scene, &window);
    world.start();

    window.show();


    return app.exec();
}
