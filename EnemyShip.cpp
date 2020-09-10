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



	//if (moveTimer.getElapsedTime().asMilliseconds() < 500)
	//{
	//	setVel(pathing[0]);
	//}
	//else if (moveTimer.getElapsedTime().asMilliseconds() < 1000)
	//{
	//}

}