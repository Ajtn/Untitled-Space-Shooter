#include "Ship.h"
#include <iostream>

Ship::Ship()
{
	equipGunType.damage = 0;
	equipGunType.fireDelay = 0;
	equipGunType.projectileVel.xVel = 0;
	equipGunType.projectileVel.yVel = 0;
	equipGunType.projectileRadius = 0;
	hp = 5;
	hpCap = 5;

}
/*
//one of these contructors is probably redundent *** requires assessment
Ship::Ship(gunType initialGunType, int initialHp, float initialXPos,
	float initialYPos, velocity initialVel, bool initialFriendly, int initialRadius)
	:GameObject(initialXPos, initialYPos, initialVel, initialFriendly, initialRadius)
{
	equipGunType = initialGunType;
	hpCap = initialHp;
	hp = hpCap;
}
*/

Ship::Ship(gunType initialGunType, int initialHp, float initialXPos,
	float initialYPos, bool initialFriendly, int initialRadius)
	:GameObject(initialXPos, initialYPos, initialFriendly, initialRadius)
{
	equipGunType = initialGunType;
	hpCap = initialHp;
	hp = hpCap;
}



int Ship::getHp() const
{
	return hp;
}



/*

//Creates a projectile game object based on current gun type
//then sets fire delay (also based on gun type)
Projectile Ship::shoot()
{



	//damage projectile will deal to be defined in switch statement
	//fire delay typically going down with higher values
	//there will be exceptions for particularly powerful projectiles
	//switch values of 10 or greater are used for enemy ships


	//having fireDelay in this switch statement is computationally inneficient but neater for current build


	switch (gunType)
	{
	case 1:
		damage = 1;
		fireDelay = 185;
		break;

	case 2:
		damage = 2;
		fireDelay = 160;
		break;

	case 3:
		damage = 4;
		fireDelay = 20;
		break;

	case 4:
		damage = 1;
		fireDelay = 185;
		break;

	case 5:
		damage = 2;
		fireDelay = 160;
		break;

	case 6:
		damage = 4;
		fireDelay = 20;
		break;

	case 7:
		damage = 1;
		fireDelay = 185;
		break;

	case 8:
		damage = 2;
		fireDelay = 160;
		break;

	case 9:
		damage = 4;
		fireDelay = 20;
		break;

	case 10:
		damage = 1;
		initialVel.yVel = 0.6f;
		fireDelay = 385;
		break;

	case 11:
		damage = 1;
		fireDelay = 350;
		break;

	case 12:
		damage = 2;
		fireDelay = 160;
		break;

	case 13:
		damage = 4;
		fireDelay = 20;
		break;

	case 14:
		damage = 1;
		fireDelay = 185;
		break;

	case 15:
		damage = 2;
		fireDelay = 160;
		break;

	case 16:
		damage = 4;
		fireDelay = 20;
		break;
	default:
		damage = 0;
		break;
	}


	return Projectile(this->getXPos() + this->getRadius() - projectileRadius, this->getYPos(),
		initialVel, this->getFriendly(), damage, projectileRadius);
}
*/

Projectile Ship::shoot()
{
	shotTimer.restart();

	return Projectile(getXPos() + getRadius() - equipGunType.projectileRadius, getYPos(), equipGunType.projectileVel,
		getFriendly(), equipGunType.damage, equipGunType.projectileRadius);
}


void Ship::takeDamage(int damage)
{
	hp = hp - damage;
}


void Ship::setGunType(gunType newGunType)
{
	equipGunType = newGunType;
}


int Ship::getFireDelay() const
{
	return equipGunType.fireDelay;
}

int Ship::getTime() const
{
	return shotTimer.getElapsedTime().asMilliseconds();
}
