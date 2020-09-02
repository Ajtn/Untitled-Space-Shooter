#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Ship :
    public GameObject
{
private:
    int fireDelay;
    int gunType;
    int hp;



public:

    Ship();

    Ship(int initialFireDelay, int initialGunType, int initialHp);

    int getHp() const;
    //int getGunType() const;
    //int getFireDelay() const;


    Projectile shoot();

    void setHp(int newHp);
    void setGunType(int newGunType);
    void upgradeGunType();
    void setFireDelay(int newFireDelay);

};

