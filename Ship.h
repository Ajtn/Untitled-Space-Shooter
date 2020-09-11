#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Ship :
    public GameObject
{
private:


    //different guns will do different amounts of damage and incur different fire delay
    gunType equipGunType;

    //defines ships current maximum hp value
    int hpCap;

    //defines ships current hp value, ie how much damage it can sustain before death
    int hp;

    //Clock to count gun cool down
    sf::Clock shotTimer;

    bool takeDamage(int damage);

    bool collision(float otherObjectX, float otherObjectY, int otherObjRadius);

protected:
    void heal(int healVal);

    void changeHpCap();

public:

    Ship();

    /*
    Ship(gunType equipGunType, int initialHp, float initialXPos,
        float initialYPos, velocity initialVel, bool initialFriendly, int initialRadius);

    */

    Ship(gunType equipGunType, int initialHp, float initialXPos,
        float initialYPos, bool initialFriendly, int initialRadius);

    int getHp() const;


    Projectile shoot();


    void setGunType(gunType newGunType);

    int getFireDelay() const;

    int getTime() const;

    bool hostileCollision();


};

