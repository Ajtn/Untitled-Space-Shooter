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


    //have set time of invincibility at the start of the clock
    //invibility powerup will reset clock
    sf::Clock invincibility;

    void move(int direction);

    void directionalInput();

public:

    PlayerShip(gunType initialGunType);


    void getUpgrade(PowerUp upgrade);

    bool checkInvincible();

    Projectile checkInput();
};

