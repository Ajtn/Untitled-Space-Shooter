#include "Game.h"

void Game::enemiesShoot()
{
	//loop iterates 10 times because that is currently max length of array
	//should define as constant to declare in both spaces with one value
	for (int i = 0; i < 10; i++)
	{
		enemyShots[currentEnemy] = enemies[i].shoot();
		if (currentEnemyShot > 18)
		{
			currentEnemyShot = 0;
		}
		else
		{
			currentEnemyShot++;
		}
	}
}

void Game::playerInput()
{
	Projectile temp = player.checkInput();

	if (temp.getDamage() > 0)
	{
		playerShots[currentShot] = temp;

		if (currentShot > 18)
		{
			currentShot = 0;
		}
		else
		{
			currentShot++;
		}
	}
}

Game::Game(PlayerShip currentPlayer, EnemyShip thisWorldsEnemies[])
{
	//Array of all player guns (damage, fireDelay, (xVelocity, yVelocity), projectileRadius)

	//0)Basic starting gun
	playerArsenal[0] = { 1, 185, {0, -0.65}, 8 };
	//1) low frequency, large, high damage
	playerArsenal[1] = { 3, 300, {0, -0.65}, 25 };
	//2) mini gun
	playerArsenal[2] = { 1, 85, {0, -0.65}, 5 };
	//3) higher damage standard gun
	playerArsenal [3]= { 2, 185, {0, -0.65}, 8 };
	//4) super high dps
	playerArsenal[4] = { 5, 100, {0, -0.65}, 8 };

	player = currentPlayer;
}

