#include "PlayerShip.h"
#include <iostream>


PlayerShip::PlayerShip()
	:Ship(0, 1, 5, 1920 / 2, 1050, true, 50)
{

	speed = 1.234343f;
	std::wcout << speed;
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
		//move right
		setXVel(speed);
		setYVel(0);
		break;
	case 2:
		//move left
		setXVel(-speed);
		setYVel(0);
		break;
	case 3:
		//move up and right
		setXVel(speed);
		setYVel(-speed);
		break;
	case 4:
		//move up and left
		setXVel(-speed);
		setYVel(-speed);
		break;
	case 5:
		//move down and right
		setXVel(speed);
		setYVel(speed);
		break;
	case 6:
		//move down and left
		setXVel(-speed);
		setYVel(speed);
		break;
	case 7:
		//move up
		setXVel(0);
		setYVel(-speed);
		break;
	case 8:
		//move down
		setXVel(0);
		setYVel(speed);
		break;
	default:
		//no movement
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