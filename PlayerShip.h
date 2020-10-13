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

    void move(int direction);

    void directionalInput();

    void choseGun(int chosenGun);

    int lives;

    sf::Texture hpTexture;

    sf::Sprite hpBar;



public:


    PlayerShip();

    void getUpgrade(PowerUp upgrade);

    bool checkInvincible();

    Projectile checkInput();

    sf::Sprite getHp();

    bool die();
};

