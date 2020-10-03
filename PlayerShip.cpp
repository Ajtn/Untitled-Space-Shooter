#include "PlayerShip.h"

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
		tempVel.xVel = -speed;
		tempVel.yVel = 0;
		break;
	case 3:
		//move up and right
		tempVel.xVel = 0.7 * speed;
		tempVel.yVel = 0.7 * -speed;
		break;
	case 4:
		//move up and left
		tempVel.xVel = 0.7 * -speed;
		tempVel.yVel = 0.7 * -speed;
		break;
	case 5:
		//move down and right
		tempVel.xVel = 0.7 * speed;
		tempVel.yVel = 0.7 * speed;
		break;
	case 6:
		//move down and left
		tempVel.xVel = 0.7 * -speed;
		tempVel.yVel = 0.7 * speed;
		break;
	case 7:
		//move up
		tempVel.xVel = 0;
		tempVel.yVel = -speed;
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


void PlayerShip::directionalInput()
{
	int cInput;

	//input for negative x direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		//input for negative x and positive y
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			cInput = 4;
		}
		//input for negative x and negative y
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			cInput = 6;
		}
		//input for negative x neutral y
		else
		{
			cInput = 2;
		}
	}
	//positive x direction
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		//input for positive x and positive y
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			cInput = 3;
		}
		//input for positive x and negative y
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			cInput = 5;
		}
		//input for positive x and neutral y
		else
		{
			cInput = 1;
		}
	}
	//neutral x input values
	else
	{
		//input for neutral x and positive y
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			cInput = 7;
		}
		//input for neutral x and negative y
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			cInput = 8;
		}
		//blank input
		else
		{
			cInput = 0;
		}
	}
	move(cInput);
}

void PlayerShip::choseGun(int chosenGun)
{
	setGunType(arsenal[chosenGun]);
}

PlayerShip::PlayerShip()
	:Ship(5, 1920 / 2, 1050, true, 50, "Res/spritesheets/ship.png", sf::Rect<int>(32, 0, 16, 24))
{
	const float bs = 12;
	//Array of all player guns (damage, fireDelay, (xVelocity, yVelocity), projectileRadius)
	//0)Basic starting gun
	arsenal[0] = { 1, 185, {bs * 0, -bs}, 8 };
	//1) low frequency, large, high damage
	arsenal[1] = { 3, 300, {bs * 0,-bs}, 25 };
	//2) mini gun
	arsenal[2] = { 1, 85, {bs * 0, -bs}, 5 };
	//3) higher damage standard gun
	arsenal[3] = { 2, 185, {bs * 0, -bs}, 8 };
	//4) super high dps
	arsenal[4] = { 5, 100, {bs * 0, -bs}, 8 };

	lives = 3;

	choseGun(0);

	speed = 10;
	invincibility = 0;

}


void PlayerShip::getUpgrade(PowerUp upgrade)
{
	switch (upgrade.getType())
	{
	case 1:
		choseGun(upgrade.getValue());
		break;
	case 2:
		changeHpCap(upgrade.getValue());
		break;
	case 3:
		heal(upgrade.getValue());
		break;
	case 4:
		invincibility = upgrade.getValue();
		invincibilityTimer.restart();
		break;
	case 5:
		lives++;
		break;
	default:
		break;
	}
}

bool PlayerShip::checkInvincible()
{
	if (invincibilityTimer.getElapsedTime().asMilliseconds() < invincibility)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Projectile PlayerShip::checkInput()
{
	directionalInput();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		return this->shoot();
	}
	else
	{
		return Projectile();
	}

}

//called when the player takes lethal damage, returns true if another life is available
//otherwise it returns false signalling a game over
bool PlayerShip::die()
{
	lives--;
	if (lives < 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}