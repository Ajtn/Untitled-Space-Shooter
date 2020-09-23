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

    gunType arsenal[8];

    int invincibility;

    sf::Clock invincibilityTimer;

    void move(int direction);

    void directionalInput();

    void choseGun(int chosenGun);


public:

    PlayerShip(gunType initialGunType);

    PlayerShip();

    void getUpgrade(PowerUp upgrade);

    bool checkInvincible();

    Projectile checkInput();
};

