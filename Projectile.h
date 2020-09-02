#pragma once
#include "GameObject.h"
class Projectile :
    public GameObject
{
private:

    //defines how much damage it does to an object upon collision
    int damage;

public:
    Projectile(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly, int initialDamage);
};

