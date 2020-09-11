#pragma once
#include "GameObject.h"
class Projectile :
    public GameObject
{
private:

    //defines how much damage it does to an object upon collision
    int damage;

public:
    Projectile(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialDamage, int initialRadius);

    Projectile();

    int getDamage() const;
};

