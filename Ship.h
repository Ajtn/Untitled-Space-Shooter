#pragma once
#include "GameObject.h"
class Ship :
    public GameObject
{
private:
    int fireDelay;
    int gunType;
    int hp;



public:

    Ship();

    Ship(int defFireDelay, int defGunType, int defHp);

    int getHp() const;
    int getGunType() const;
    int getFireDelay() const;

    void setHp(int newHp);
    void setGunType(int newGunType);
    void setFireDelay(int newFireDelay);

};

