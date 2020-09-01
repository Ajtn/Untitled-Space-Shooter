#pragma once
#include "GameObject.h"
#include "Ship.h"

class PlayerShip :
    public Ship
{
private:

    int hpCap;
    int speed;
    int invincibility;

public:

    PlayerShip();

    void shoot();

    bool takeDamage(int damage);

    void repair(int val);

    void upgradeGun();

    void move(int direction);

   //void updateState() override;

};

