#include "Ship.h"

Ship::Ship()
{
	fireDelay = 0;
	gunType = 0;
	hp = 5;

}

Ship::Ship(int defFireDelay, int defGunType, int defHp)
{
	fireDelay = defFireDelay;
	gunType = defGunType;
	hp = defHp;
}


int Ship::getHp() const
{
	return hp;
}

int Ship::getGunType() const
{
	return gunType;
}

int Ship::getFireDelay() const
{
	return fireDelay;
}

void Ship::setHp(int newHp)
{
	hp = newHp;
}


void Ship::setGunType(int newGunType)
{
	gunType = newGunType;
}

void Ship::setFireDelay(int newFireDelay)
{
	fireDelay = newFireDelay;
}