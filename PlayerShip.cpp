#include "PlayerShip.h"
#include <iostream>


PlayerShip::PlayerShip()
{
	GameObject(1920 / 2, 1050, 0, 0, true, 50);
	Ship(0, 1, 5, 5);
	speed = 1;
	invincibility = 20;

}


/*


//returns true if ship alive or false if the ship has died
bool PlayerShip::takeDamage(int damage)
{
	if (this->getHp() > 0)
	{
		this->setHp(this->getHp() - damage);
		return true;
	}
	else
	{
		return false;
	}
}


//adds val to current hp, cannot exceed hp Cap
void PlayerShip::repair(int val)
{
	if (this->getHp() + val > hpCap)
	{
		this->setHp(hpCap);
	}
	else
	{
		this->setHp(this->getHp() + val);
	}
}

*/

//accepts input from 1 - 8 and sets velocity in the x and y direction as appropriate
void PlayerShip::move(int direction)
{

	switch (direction)
	{
	case 1:
		setXVel(speed);
		setYVel(0);
		break;
	case 2:
		setXVel(-speed);
		setYVel(0);
		break;
	case 3:
		setXVel(speed);
		setYVel(-speed);
		break;
	case 4:
		setXVel(-speed);
		setYVel(-speed);
		break;
	case 5:
		setXVel(speed);
		setYVel(speed);
		break;
	case 6:
		setXVel(-speed);
		setYVel(speed);
		break;
	case 7:
		setXVel(0);
		setYVel(-speed);
		break;
	case 8:
		setXVel(0);
		setYVel(speed);
		break;
	default:
		setXVel(0);
		setYVel(0);
		break;
	}
}


/**
void PlayerShip::updateState()
{
	
}
**/