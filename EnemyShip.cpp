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
	switch (moveTimer.getElapsedTime().asMilliseconds())
	{
	case 00:
		setVel(pathing[0]);
		break;
	case 500:
		setVel(pathing[1]);
		break;
	case 1000:
		setVel(pathing[2]);
		break;
	case 1500:
		setVel(pathing[3]);
		break;
	case 2000:
		setVel(pathing[4]);
		break;
	case 2500:
		setVel(pathing[5]);
		break;
	case 3000:
		setVel(pathing[6]);
		break;
	case 3500:
		setVel(pathing[7]);
		break;
	case 4000:
		setVel(pathing[8]);
		break;
	case 4500:
		setVel(pathing[9]);
		break;
	case 5000:
		setVel(pathing[10]);
		break;
	case 5500:
		setVel(pathing[11]);
		moveTimer.restart();
		break;

	default:
		break;
	}

}