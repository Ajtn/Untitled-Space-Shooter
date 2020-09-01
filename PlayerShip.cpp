#include "PlayerShip.h"
#include <iostream>


PlayerShip::PlayerShip()
{
	hpCap = 5;
	speed = 1;
	invincibility = 20;
	manualPosition(1920 / 2, 1050);

}



//checks gun type then shoots appropriate weapon type
void PlayerShip::shoot()
{
	//cout << "pew pew" << ;
}

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


//probably going to be changed to having int input based on upgrade
void PlayerShip::upgradeGun()
{
	this->setGunType(this->getGunType() + 1);
}


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
		setYVel(speed);
		break;
	case 4:
		setXVel(-speed);
		setYVel(speed);
		break;
	case 5:
		setXVel(speed);
		setYVel(-speed);
		break;
	case 6:
		setXVel(-speed);
		setYVel(-speed);
		break;
	case 7:
		setXVel(0);
		setYVel(speed);
		break;
	case 8:
		setXVel(0);
		setYVel(-speed);
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