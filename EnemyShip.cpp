#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
	makeInvisible();
}

EnemyShip::EnemyShip(Pathing initialPathing, gunType initialGunType, int initialHp, float initialXPos, float initialYPos,
	bool initialFriendly, int initialRadius, std::string spriteAddress, sf::Rect<int> initialSelectedSprite)
	:Ship(initialGunType, initialHp, initialXPos, initialYPos, initialFriendly, initialRadius, spriteAddress, initialSelectedSprite)
{
	pathing = initialPathing;
	setVel({0, 0});
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