#include "PlayerShip.h"


PlayerShip::PlayerShip(gunType initialGunType)
	:Ship(initialGunType, 5, 1920 / 2, 1050, true, 50)
{

	speed = 0.375f;

}



//accepts input from 1 - 8 and sets velocity in the x and y direction as appropriate
//all diagonaal movements slowed
void PlayerShip::move(int direction)
{
	velocity tempVel;

	switch (direction)
	{
	case 1:
		//move right
		tempVel.xVel = speed;
		tempVel.yVel = 0;
		break;
	case 2:
		//move left
		tempVel.xVel = - speed;
		tempVel.yVel = 0;
		break;
	case 3:
		//move up and right
		tempVel.xVel = 0.7 * speed;
		tempVel.yVel = 0.7 * - speed;
		break;
	case 4:
		//move up and left
		tempVel.xVel = 0.7 * - speed;
		tempVel.yVel = 0.7 * - speed;
		break;
	case 5:
		//move down and right
		tempVel.xVel = 0.7 * speed;
		tempVel.yVel = 0.7 * speed;
		break;
	case 6:
		//move down and left
		tempVel.xVel = 0.7 * - speed;
		tempVel.yVel = 0.7 * speed;
		break;
	case 7:
		//move up
		tempVel.xVel = 0;
		tempVel.yVel = - speed;
		break;
	case 8:
		//move down
		tempVel.xVel = 0;
		tempVel.yVel = speed;
		break;
	default:
		//no movement
		tempVel.xVel = 0;
		tempVel.yVel = 0;
		break;
	}
	if (getXPos() > 1920 - getRadius() && tempVel.xVel > 0)
	{
		tempVel.xVel = 0;
	}
	else if (getXPos() < 0 - getRadius() && tempVel.xVel < 0)
	{
		tempVel.xVel = 0;
	}

	if (getYPos() > 1080 - getRadius() && tempVel.yVel > 0)
	{
		tempVel.yVel = 0;
	}
	else if (getYPos() < 0 - getRadius() && tempVel.yVel < 0)
	{
		tempVel.yVel = 0;
	}

	setVel(tempVel);
}


bool PlayerShip::checkInvincible()
{
	if (invincibility.getElapsedTime().asMilliseconds() > 2000)
	{
		return true;
	}
	else
	{
		return false;
	}
}