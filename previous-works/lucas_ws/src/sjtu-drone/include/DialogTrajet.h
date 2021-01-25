#ifndef DIALOGTRAJET_H
#define DIALOGTRAJET_H

#include <QDialog>
#include "drone_object_ros.h"

namespace Ui {
class DialogTrajet;
}

class DialogTrajet : public QDialog
{
    Q_OBJECT  
public:
    DroneObjectROS* drone;
public:
    explicit DialogTrajet(QWidget *parent = 0);
    ~DialogTrajet();
    void setDrone(DroneObjectROS& drone_){
        this->drone = &drone_;
    }
    void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    void testPositionControl();
private:
    Ui::DialogTrajet *ui;
};

#endif // DIALOGTRAJET_H
