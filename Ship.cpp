#include "Ship.h"


bool Ship::takeDamage(int damage)
{
	hp = hp - damage;

	if (hp < 1)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool Ship::collision(float otherObjectX, float otherObjectY, int otherObjRadius)
{
	if (abs(getXPos() - otherObjectX) < (getRadius() + otherObjRadius))
	{
		if (abs(getYPos() - otherObjectY) < (getRadius() + otherObjRadius))
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Ship::heal(int healVal)
{
	if (hp + healVal > hpCap)
	{
		hp = hpCap;
	}
	else
	{
		hp = hp + healVal;
	}
}

//may want to set upper bound here
void Ship::changeHpCap()
{
	hpCap = hpCap + 2;
	heal(2);
}


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




//Creates a projectile game object based on current gun type
Projectile Ship::shoot()
{
	shotTimer.restart();

	return Projectile(getXPos() + getRadius() - equipGunType.projectileRadius, getYPos(), equipGunType.projectileVel,
		getFriendly(), equipGunType.damage, equipGunType.projectileRadius);
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

bool Ship::hostileCollision()
{

}

