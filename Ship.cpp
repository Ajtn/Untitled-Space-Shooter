#include "Ship.h"
#include <iostream>

Ship::Ship()
{
	fireDelay = 0;
	gunType = 0;
	hp = 5;
	hpCap = 5;

}

Ship::Ship(int initialFireDelay, int initialGunType, int initialHp, float initialXPos,
	float initialYPos, velocity initialVel, bool initialFriendly, int initialRadius)
	:GameObject(initialXPos, initialYPos, initialVel, initialFriendly, initialRadius)
{
	fireDelay = initialFireDelay;
	gunType = initialGunType;
	hpCap = initialHp;
	hp = hpCap;
}

Ship::Ship(int initialFireDelay, int initialGunType, int initialHp, float initialXPos,
	float initialYPos, bool initialFriendly, int initialRadius)
	:GameObject(initialXPos, initialYPos, initialFriendly, initialRadius)
{
	fireDelay = initialFireDelay;
	gunType = initialGunType;
	hpCap = initialHp;
	hp = hpCap;
}



int Ship::getHp() const
{
	return hp;
}




//Creates a projectile game object based on current gun type
//then sets fire delay (also based on gun type)
Projectile Ship::shoot()
{
	velocity initialVel;
	initialVel.xVel = 0;
	initialVel.yVel = -0.01f;

	std::cout << initialVel.xVel;


	int damage;

	//damage projectile will deal to be defined in switch statement
	//fire delay typically going down with higher values
	//there will be exceptions for particularly powerful projectiles

	switch (gunType)
	{
	case 1 :
		damage = 1;
		fireDelay = 500;
		break;

	case 2:
		damage = 2;
		fireDelay = 25;
		break;

	case 3:
		damage = 4;
		fireDelay = 20;
		break;
	default:
		damage = 0;
		break;
	}

	std::cout << initialVel.yVel;

	return Projectile(this->getXPos(), this->getYPos(), initialVel, this->getFriendly(), damage, 2);
}



void Ship::takeDamage(int damage)
{
	hp = hp - damage;
}


void Ship::setGunType(int newGunType)
{
	gunType = newGunType;
}

void Ship::upgradeGunType()
{
	gunType++;
}

int Ship::getFireDelay() const
{
	return fireDelay;
}

void Ship::setFireDelay(int newFireDelay)
{
	fireDelay = newFireDelay;
}