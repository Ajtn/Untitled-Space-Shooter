#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
	makeInvisible();
}

EnemyShip::EnemyShip(Pathing initialPathing, gunType initialGunType, int initialHp, float initialXPos,
	float initialYPos, bool initialFriendly, int initialRadius)
	:Ship(initialGunType, initialHp, initialXPos, initialYPos, initialFriendly, initialRadius)
{
	pathing = initialPathing;
}


void EnemyShip::move()
{
	//Checks if 250 milliseconds have passedd and then sets velocity according to pathing object and restarts moveTimer

	if (moveTimer.getElapsedTime().asMilliseconds() > 250)
	{
		moveTimer.restart();
		setVel(pathing.getVelocity());
	}
}


void EnemyShip::resetMoveClock()
{
	moveTimer.restart();
}