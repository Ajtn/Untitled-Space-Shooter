#include "Ship.h"

Ship::Ship()
{
	fireDelay = 0;
	gunType = 0;
	hp = 5;

}

Ship::Ship(int initialFireDelay, int initialGunType, int initialHp)
{
	fireDelay = initialFireDelay;
	gunType = initialGunType;
	hp = initialHp;
}


int Ship::getHp() const
{
	return hp;
}

/*
int Ship::getGunType() const
{
	return gunType;
}


int Ship::getFireDelay() const
{
	return fireDelay;
}

*/


//Creates a projectile game object based on current gun type
//then sets fire delay (also based on gun type)
Projectile Ship::shoot()
{
	Projectile projectile;
	//projectile to be defined in switch statement
	//fire delay typically going down with higher values
	//there will be exceptions for particularly powerful projectiles

	switch (gunType)
	{
	case 1 :
		projectile = Projectile();
		fireDelay = 30;
		break;

	case 2:
		projectile = Projectile();
		fireDelay = 25;
		break;

	case 3:
		projectile = Projectile();
		fireDelay = 20;
		break;
	default:
		break;
	}

	return projectile;
}


void Ship::setHp(int newHp)
{
	hp = newHp;
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