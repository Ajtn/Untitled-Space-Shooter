#pragma once
#include "Ship.h"
#include "Pathing.h"
#include <iostream>

class EnemyShip :
    public Ship
{
private:
    Pathing pathing;

    //Move timer used to check how long since trajectory was last modified
    sf::Clock moveTimer;

    //defines how much damage object does when colliding with player
    int collisionDamage;


public:
    EnemyShip();

    EnemyShip(Pathing initialPathing, gunType initialGunType, int initialHp, float initialXPos, float initialYPos,
        bool initialFriendly, int initialRadius, std::string spriteAddress, sf::Rect<int> initialSelectedSprite);

    void move();

    void resetMoveClock();
};

