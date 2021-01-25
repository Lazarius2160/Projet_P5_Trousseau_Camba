#include <DialogKeyboard.h>
#include <QtWidgets>
#include "ui_DialogKeyboard.h"

DialogKeyboard::DialogKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogKeyboard)
{
    ui->setupUi(this);
}

DialogKeyboard::~DialogKeyboard()
{
    delete ui;
}

void DialogKeyboard::keyPressEvent(QKeyEvent *event){
    if(!drone)
        return ;
    char key = event->key();
    std::cout << "key:" << key << std::endl;

/* debut du préenregistrement*/
    	drone->takeOff();
	drone->moveTo(1,0,1);
	sleep(3);
	drone->yaw(-1.0f);
	sleep(3);
	drone->moveTo(1,0,-1);
	sleep(3);
	drone->yaw(-1.0f);
	sleep(3);

/*fin du préenregistrement*/
    event->accept();
}

void DialogKeyboard::keyReleaseEvent(QKeyEvent *event){
    if(!drone)
        return ;
    char key = event->key();
    if (!event->isAutoRepeat()){
        std::cout << "key:" << key << " has been released !" << std::endl;
        if( !drone->isPosctrl)
            drone->hover();
        event->accept();
    }else{
        event->ignore();
    }
}

void DialogKeyboard::testPositionControl(){
    if(drone->isPosctrl){
        drone->posCtrl(false);
        std::cout << "position control off!" << std::endl;
    }
    else{
        drone->posCtrl(true);
        std::cout << "(0.5,-1.5,6)" << std::endl;
        drone->moveTo(0.5,-1.5,2);
        sleep(5);
        drone->moveTo(0.5,1.5,2);
        sleep(5);
        drone->moveTo(-3,1.5,2);
        sleep(5);
        drone->moveTo(-3,-1.5,2);
        sleep(5);
        drone->moveTo(0.5,-1.5,2);
        sleep(5);
    }
}    

    	


