#pragma once
#include "GameObject.h"
#include "Ship.h"
#include "PowerUp.h"

class PlayerShip :
    public Ship
{
private:

 
     //Speed determines velocity when moving
    float speed;

    //Invincibility will tick down each frame and prevent damage
    //being taken while it is > 0
    int invincibility;

public:

    PlayerShip(gunType initialGunType);



    void move(int direction);

    void getUpgrade(PowerUp upgrade);
};

