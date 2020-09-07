#include "Ship.h"
#include <iostream>

Ship::Ship()
{
	fireDelay = 0;
	gunType = 0;
	hp = 5;
	hpCap = 5;

}

Ship::Ship(int initialFireDelay, int initialGunType, int initialHp)
{
	GameObject();
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
	std::wcout << " guntype = ";
	std::wcout << gunType;

	int damage;

	//damage projectile will deal to be defined in switch statement
	//fire delay typically going down with higher values
	//there will be exceptions for particularly powerful projectiles

	switch (gunType)
	{
	case 1 :
		damage = 1;
		fireDelay = 30;
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

	return Projectile(this->getXPos(), this->getYPos(), 0, 2, this->getFriendly(), damage, 2);
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


void Ship::setFireDelay(int newFireDelay)
{
	fireDelay = newFireDelay;
}