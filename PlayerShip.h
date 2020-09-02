#pragma once
#include "GameObject.h"
#include "Ship.h"

class PlayerShip :
    public Ship
{
private:

    //HP Cap is the max health a ship can have, can be upgraded

    //Speed determines velocity when moving

    //Invincibility will tick down each frame and prevent damage
    //being taken while it is > 0

    int hpCap;
    int speed;
    int invincibility;

public:

    PlayerShip();

   

    bool takeDamage(int damage);

    void repair(int val);


    void move(int direction);

   //void updateState() override;

};

