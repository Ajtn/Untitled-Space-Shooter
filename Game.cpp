#include "Game.h"
#include <iostream>


void Game::spawnEnemies()
{
	//Checks last modified member of enemy array and spawn timer to ensure the corrrect
	//enemies are spawned at the right time

	if (currentEnemy < 1)
	{
		enemies[currentEnemy] = enemyTemplates[4];
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if ((spawnTimer.getElapsedTime().asMilliseconds() > 2000) && currentEnemy < 2)
	{
		enemies[currentEnemy] = enemyTemplates[4];
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 4000 && currentEnemy < 3)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 6000 && currentEnemy < 4)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 8000 && currentEnemy < 5)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 12000 && currentEnemy < 6)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 14000 && currentEnemy < 7)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 16000 && currentEnemy < 8)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 20000 && currentEnemy < 9)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 22000 && currentEnemy < 10)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[4]);
		enemies[currentEnemy].resetMoveClock();
		currentEnemy++;
	}
	//resets timers and counters to start a new wave of enemies
	else if (spawnTimer.getElapsedTime().asMilliseconds() > 30000)
	{
		spawnTimer.restart();
		currentEnemy = 0;

	}

}

void Game::enemiesShoot()
{
	//iterates through all visible enemies and calls the shoot function
	Projectile temp;
	//loop iterates 10 times because that is currently max length of array
	//should define as constant to declare in both spaces with one value
	for (int i = 0; i < 10; i++)
	{
		if (enemies[i].getVisible())
		{
			temp = enemyShots[currentEnemyShot] = enemies[i].shoot();

			if (temp.getDamage() > 0)
			{
				enemyShots[currentEnemyShot] = temp;

				if (currentEnemyShot > 48)
				{
					currentEnemyShot = 0;
				}
				else
				{
					currentEnemyShot++;
				}
			}
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

void Game::updateObjects(sf::RenderWindow& screen)
{
	//calls all velocity and position update functions for all visible objects

	for (int i = 0; i < 10; i++)
	{
		if (enemies[i].getVisible())
		{
			
			enemies[i].move();
			screen.draw(enemies[i].updateObject());
		}
	}

	for (int i = 0; i < 50; i++)
	{
		if (enemyShots[i].getVisible())
		{
			screen.draw(enemyShots[i].updateObject());
		}
	}

	for (int i = 0; i < 20; i++)
	{
		if (playerShots[i].getVisible())
		{
			screen.draw(playerShots[i].updateObject());
		}
	}


	screen.draw(player.updateObject());
}

void Game::checkCollisions()
{
	//Checks all player shots against all enemy ships
	//shots disappear if they hit a ship and damage is applied in ships collision function
	for (int i = 0; i < 10; i++)
	{
		if (enemies[i].getVisible())
		{
			for (int j = 0; j < 20; j++)
			{
				if (playerShots[j].getVisible())
				{
					if (enemies[i].hostileCollision(playerShots[j]))
					{
						playerShots[j].makeInvisible();
					}
				}
			}
		}
	}

	//checks all enemy shots against player ship
	for (int i = 0; i < 50; i++)
	{
		if (enemyShots[i].getVisible())
		{
			if (player.hostileCollision(enemyShots[i]))
			{
				enemyShots[i].makeInvisible();
			}
		}
	}

	//new collision function needed for enemy ships directly crashing into player
}



Game::Game(EnemyShip thisWorldsEnemies[10])
{
	//sets all default counter values at 0
	currentEnemy = 0;
	currentEnemyShot = 0;
	currentShot = 0;

	//set enemy templates from parameter

	for (int i = 0; i < 10; i++)
	{
		enemyTemplates[i] = thisWorldsEnemies[i];
	}



	player = PlayerShip();
}

void Game::run()
{
	sf::RenderWindow screen(sf::VideoMode(1920, 1080), "Untitled_SpaceShooter");

	//Current frame rate ~ 1000 and timers based on this, times need to be modified to fit 60fps before this can be added
	screen.setFramerateLimit(60);

	spawnTimer.restart();
	while (screen.isOpen())
	{
		sf::Event event;

		while (screen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				screen.close();
			}
		}
		screen.clear();
		enemiesShoot();
		spawnEnemies();
		playerInput();
		checkCollisions();
		updateObjects(screen);

		screen.display();

	}

}