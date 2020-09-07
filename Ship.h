#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Ship :
    public GameObject
{
private:

    //defines cool down before ship can fire again
    int fireDelay;

    //different guns will do different amounts of damage and incur different fire delay
    int gunType;

    //defines ships current maximum hp value
    int hpCap;

    //defines ships current hp value, ie how much damage it can sustain before death
    int hp;


public:

    Ship();

    Ship(int initialFireDelay, int initialGunType, int initialHp, float initialXPos,
        float initialYPos, velocity initialVel, bool initialFriendly, int initialRadius);

    Ship(int initialFireDelay, int initialGunType, int initialHp, float initialXPos,
        float initialYPos, bool initialFriendly, int initialRadius);

    int getHp() const;


    Projectile shoot();

    void takeDamage(int damage);

    void setGunType(int newGunType);
    void upgradeGunType();
    int getFireDelay() const;
    void setFireDelay(int newFireDelay);

};

