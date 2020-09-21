#pragma once
#include "Ship.h"

class EnemyShip :
    public Ship
{
private:
    velocity pathing[12];
    sf::Clock moveTimer;


public:
    EnemyShip();

    EnemyShip(velocity initialPathing[12], gunType initialGunType, int initialHp, float initialXPos,
        float initialYPos, bool initialFriendly, int initialRadius);

    void move();

    void resetMoveClock();
};

