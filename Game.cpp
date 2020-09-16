#include "Game.h"

void Game::spawnEnemies()
{
	if ((spawnTimer.getElapsedTime().asMilliseconds() < 2000) && currentEnemy < 1)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[1]);
		currentEnemy++;
	}
	else if ((spawnTimer.getElapsedTime().asMilliseconds() < 4000) && currentEnemy < 2)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[1]);
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() < 6000 && currentEnemy < 3)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[1]);
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() < 8000 && currentEnemy < 5)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[1]);
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() < 10000 && currentEnemy < 6)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[1]);
		currentEnemy++;
	}
	else if (spawnTimer.getElapsedTime().asMilliseconds() < 12000 && currentEnemy < 4)
	{
		enemies[currentEnemy] = EnemyShip(enemyTemplates[1]);
		currentEnemy++;
	}

	if (spawnTimer.getElapsedTime().asMilliseconds() > 20000)
	{
		spawnTimer.restart();
		currentEnemy = 0;
	}
}

void Game::enemiesShoot()
{
	Projectile temp;
	//loop iterates 10 times because that is currently max length of array
	//should define as constant to declare in both spaces with one value
	for (int i = 0; i < 10; i++)
	{
		temp = enemyShots[currentEnemy] = enemies[i].shoot();

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

void Game::updateObjects()
{
	for (int i = 0; i < 10; i++)
	{
		if (enemies[i].getVisible());
		{
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
				if (enemies[i].hostileCollision(playerShots[j]))
				{
					playerShots[j].makeInvisible();
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

Game::Game(PlayerShip currentPlayer, EnemyShip thisWorldsEnemies[], velocity premadePathing[8][12])
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


	//Array of all enemy guns (damage, fireDelay, (xVel, yVel), radius)
	//0) basic small, low damage, slow shot
	enemyArsenal[0] = { 1, 500, { 0, 0.38f }, 8 };
	//1) slightly high frequency
	enemyArsenal[1] = { 1, 350, { 0, 0.38f }, 8 };
	//2) double damage 
	enemyArsenal[2] = { 2, 500, {0, 0.38f}, 8 };
	//3) big bois
	enemyArsenal[3] = { 1, 500, {0, 0.38f}, 16 };
	//4) fast and frequent
	enemyArsenal[4] = { 1, 300, {0, 0.38f}, 8 };

	//set pathing values from parameter
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			pathing[i][j] = premadePathing[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		enemyTemplates[i] = thisWorldsEnemies[i];
	}



	player = currentPlayer;
}

bool Game::run()
{
	sf::RenderWindow screen(sf::VideoMode(1920, 1080), "Untitled_SpaceShooter");
	//Current frame rate ~ 1000 and timers based on this, times need to be modified to fit 60fps before this can be added
	//screen.setFramerateLimit(60);
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

		enemiesShoot();
		spawnEnemies();
		playerInput();
		checkCollisions();
		updateObjects();

	}

}