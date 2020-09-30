#pragma once
#include "Ship.h"
#include "Pathing.h"
#include <iostream>

class EnemyShip :
    public Ship
{
private:
    Pathing pathing;
    sf::Clock moveTimer;


public:
    EnemyShip();

    EnemyShip(Pathing initialPathing, gunType initialGunType, int initialHp, float initialXPos,
        float initialYPos, bool initialFriendly, int initialRadius);

    void move();

    void resetMoveClock();
};

