#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
	for (int i = 0; i < 12; i++)
	{
		pathing[i] = {0, 0};
		makeInvisible();
	}
}

EnemyShip::EnemyShip(velocity initialPathing[12], gunType initialGunType, int initialHp, float initialXPos,
	float initialYPos, bool initialFriendly, int initialRadius)
	:Ship(initialGunType, initialHp, initialXPos, initialYPos, initialFriendly, initialRadius)
{
	for (int i = 0; i < 12; i++)
	{
		pathing[i] = initialPathing[i];
	}
}


void EnemyShip::move()
{
	//sets the ships velocity to the pathing value appropriate to the current time in the pathing loop

	const int timeInterval = 250;

	if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval)
	{
		setVel(pathing[0]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 2)
	{
		setVel(pathing[1]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 3)
	{
		setVel(pathing[2]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 4)
	{
		setVel(pathing[3]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 5)
	{
		setVel(pathing[4]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 6)
	{
		setVel(pathing[5]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 7)
	{
		setVel(pathing[6]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 8)
	{
		setVel(pathing[7]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 9)
	{
		setVel(pathing[8]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 10)
	{
		setVel(pathing[9]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 11)
	{
		setVel(pathing[10]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < timeInterval * 12)
	{
		setVel(pathing[11]);
	}
	else
	{
		moveTimer.restart();
	}
}


void EnemyShip::resetMoveClock()
{
	moveTimer.restart();
}