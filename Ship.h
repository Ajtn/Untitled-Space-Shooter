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

    Ship(int initialFireDelay, int initialGunType, int initialHp);

    int getHp() const;


    Projectile shoot();

    void takeDamage(int damage);

    void setGunType(int newGunType);
    void upgradeGunType();
    void setFireDelay(int newFireDelay);

};

