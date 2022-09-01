#ifndef MYWINDOW_H
#define MYWINDOW_H
#include "ObjectManager.h"
#include <QMap>
#include <QtGui>

//CLASS FOR THE WIDGET WINDOW, IMPLEMENTATIONS FOR KEY EVENTS

class MyWindow : public QWidget
{
public:
    MyWindow(void);

protected:
    virtual void keyPressEvent(QKeyEvent *event); //Actions happening when pressed
    virtual void keyReleaseEvent(QKeyEvent *event); //Actions when keys released


private:
    QWidget win;
    enum Action { Accel0, Left0, Right0, Slow0, Roll0, Shoot0, Drop0, Missile0, Accel1, Left1, Right1, Slow1, Roll1, Shoot1, Drop1, Missile1, Escape };
    QMap<int, Action> actions;

};

#endif // MYWINDOW_H
