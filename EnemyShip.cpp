#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
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
	/*
	switch (std::llround(moveTimer.getElapsedTime().asSeconds()))
	{
	case 00:
		setVel(pathing[0]);
		break;
	case 1:
		setVel(pathing[1]);
		break;
	case 2:
		setVel(pathing[2]);
		break;
	case 3:
		setVel(pathing[3]);
		break;
	case 4:
		setVel(pathing[4]);
		break;
	case 5:
		setVel(pathing[5]);
		break;
	case 6:
		setVel(pathing[6]);
		break;
	case 7:
		setVel(pathing[7]);
		break;
	case 8:
		setVel(pathing[8]);
		break;
	case 9:
		setVel(pathing[9]);
		break;
	case 10:
		setVel(pathing[10]);
		break;
	case 11:
		setVel(pathing[11]);
		moveTimer.restart();
		break;

	default:
		break;
	}
	*/


	if (moveTimer.getElapsedTime().asMilliseconds() < 300)
	{
		setVel(pathing[0]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 600)
	{
		setVel(pathing[1]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 900)
	{
		setVel(pathing[2]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 1200)
	{
		setVel(pathing[3]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 1500)
	{
		setVel(pathing[4]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 1800)
	{
		setVel(pathing[5]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 2100)
	{
		setVel(pathing[6]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 2400)
	{
		setVel(pathing[7]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 2700)
	{
		setVel(pathing[8]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 3000)
	{
		setVel(pathing[9]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 3300)
	{
		setVel(pathing[10]);
	}
	else if (moveTimer.getElapsedTime().asMilliseconds() < 3600)
	{
		setVel(pathing[11]);
	}
	else
	{
		moveTimer.restart();
	}
}