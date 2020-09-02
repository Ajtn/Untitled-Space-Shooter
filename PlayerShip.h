#pragma once
#include "GameObject.h"
#include "Ship.h"

class PlayerShip :
    public Ship
{
private:

 
     //Speed determines velocity when moving
    int speed;

    //Invincibility will tick down each frame and prevent damage
    //being taken while it is > 0
    int invincibility;

public:

    PlayerShip();


    void repair(int val);


    void move(int direction);

   //void updateState() override;

};

