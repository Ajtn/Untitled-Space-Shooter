#include <array>
#include "GameObject.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Structs.h"
#include <string>
#include <SFML/Graphics.hpp>


int checkWasd()
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

	return cInput;
}

bool checkFire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		return true;
	}
	else
	{

		return false;
	}
}



int main()
{
	//multi dimensional array of movement patterns for AI, velocity to be changed incrementally to make non linear movement
//stores 8 arrays of 12 movements each
	velocity pathing[8][12] =
	{
		//0) accelerates right to left while slowly moving down
		{{0.25, 0.125}, {0.5, 0.125}, {0.25, 0.125}, {0, 0.125}, {-0.25, 0.125}, {-0.5, 0.125}, {-0.25, 0.125}, {0, 0.125}, {0.25, 0.125}, {0.5, 0.125}, {0.25, 0.125}, {0, 0.125}},
		//1)
		{{0.25, 0.25}, {0.25, 0.5}, {0.25, 0}, {-0.25, -0.25}, {-0.25, -0.5}, {-0.25, -0.25}, {0.25, 0}, {0.25, 0.25}, {0.25, 0.5}, {0.25, 0}, {0.25, 0.25}, {0.25, 0.5}},
		//2) moves left to right, comes in from right side of the screen (doesn't move vertically)
		{{-0.25, 0}, {-0.25, 0}, {-0.25, 0}, {-0.25, 0}, {-0.25, 0}, {-0.25, 0}, {0.25, 0}, {0.25, 0}, {0.25, 0}, {-0.25, 0}, {-0.25, 0}, {-0.25, 0}},
		//3) shaped loop (recurrable)
		{{-0.25, 0.125}, {-0.125, 0.125}, {-0.125, 0.25}, {0.125, 0.25}, {0.125, 0.125}, {0.25, 0.125}, {0.25, -0.125}, {0.125, -0.25}, {0.125, -0.25}, {-0.125, -0.125}, {-0.25, -0.125}, {-0.125, -0.125}},
		//4) moves up and down the screen moving to the right after each direction change
		{{0, 0.5}, {0, 0.5}, {0.25, -0.25}, {0, -0.5}, {0, -0.5}, {0.25, 0.25}, {0, 0.5}, {0, 0.5}, {0.25, -0.25}, {0, -0.5}, {0, -0.5}, {0.25, 0.25}},
		//5)
		{{1, 1 }, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1 }, {1, 1 }, {1, 1}, {1, 1}},
		//6)
		{{1, 1 }, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}},
		//7)
		{{0, 1 }, {0, 1 }, {0, 1 }, {0, 1 }, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}},
	};

	//Array of all enemy guns (damage, fireDelay, (xVelocity, yVelocity), projectileRadius)
	gunType enemyArsenal[6] =
	{
		//0) basic small, low damage, slow shot
		{1, 500, {0, 0.38f}, 8},
		//1) slightly high frequency
		{1, 350, {0, 0.38f }, 8 },
		//2) double damage 
		{2, 500, {0, 0.38f}, 8},
		//3) big bois
		{1, 500, {0, 0.38f}, 16},
		//4) fast and frequent
		{1, 300, {0, 0.38f}, 8},
		//5 nothing
		{0, 10000, {0, 0}, 0}
	};


	//Array of all player guns (damage, fireDelay, (xVelocity, yVelocity), projectileRadius)
	gunType playerArsenal[5] =
	{
		//0) Basic starting gun
		{1, 185, {0, -0.65}, 8 },
		//1) low frequency, large, high damage
		{3, 300, {0, -0.65}, 25 },
		//2) mini gun
		{1, 85, {0, -0.65}, 5 },
		//3) higher damage standard gun
		{2, 185, {0, -0.65}, 8 },
		//4) super high dps
		{5, 100, {0, -0.65}, 8 },
	};

	//Array of types of enemy ships (pathing, gunType, hp, xPos, yPos, friendly, radius)
	EnemyShip enemyTypes[6] =
	{
		//0)
		{pathing[3], enemyArsenal[0], 2, 400, 0, false, 40},
		//1)
		{pathing[1], enemyArsenal[2], 2, 1000, 0, false, 40},
		//2)
		{pathing[0], enemyArsenal[0], 2, 1500, 0, false, 40},
		//3)
		{pathing[2], enemyArsenal[0], 2, 1920, 0, false, 40 },
		//4)
		{pathing[3], enemyArsenal[0], 2, 500, 0, false, 40},
		//5
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30}
	};

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works");
	//window.setFramerateLimit(60);


	sf::Clock gameClock;

	int currentPlayerGun = 0;

	//sf::Texture texture;
	 
	//Currently causes crash as permission not available too access resource
	/*

	if (!texture.loadFromFile("Res\scrollBackgroundOne.jpg"))
	{
		std::wcout << "can't find resource";

		system("pause");
	}
	*/

	//movement input instantiated and given stationary default
	int cInput = 0;

	//playership instantiated and given gunType from arsenal
	PlayerShip test =  PlayerShip(playerArsenal[2]);

	//array of player projectiles created
	std::array<Projectile, 20> currentProjectiles;

	//counter to track most recently used value of projectile array
	int projectileCount = 0;


	//************ crash here due to default constructor of ship class ************

	//array of enemy ships
	//std::array<EnemyShip, 10> currentEnemies;
	EnemyShip currentEnemies[20] = 
	{
		EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]),
		EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]),
		EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]),
		EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]), EnemyShip(enemyTypes[5]),
	};
	int maxEnemies = 20;

	int enemyCount = 0;

	std::array<Projectile, 50> enemyProjectiles;

	int enemyProjectileCount = 0;


	//sf::Sprite background;
	//background.setTexture(texture);

	currentEnemies[0] = EnemyShip(enemyTypes[0]);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();
		}

		

		cInput = checkWasd();

		
		if ((gameClock.getElapsedTime().asMilliseconds() < 2000) && enemyCount < 1)
		{
			currentEnemies[enemyCount] = EnemyShip(enemyTypes[1]);
			enemyCount++;
		}
		else if ((gameClock.getElapsedTime().asMilliseconds() < 4000) && enemyCount < 2)
		{
			currentEnemies[enemyCount] = EnemyShip(enemyTypes[1]);
			enemyCount++;
		}
		else if (gameClock.getElapsedTime().asMilliseconds() < 6000 && enemyCount < 3)
		{
			currentEnemies[enemyCount] = EnemyShip(enemyTypes[1]);
			enemyCount++;
		}
		else if (gameClock.getElapsedTime().asMilliseconds() < 8000 && enemyCount < 5)
		{
			currentEnemies[enemyCount] = EnemyShip(enemyTypes[1]);
			enemyCount++;
		}
		else if (gameClock.getElapsedTime().asMilliseconds() < 10000 && enemyCount < 6)
		{
			currentEnemies[enemyCount] = EnemyShip(enemyTypes[1]);
			enemyCount++;
		}
		else if (gameClock.getElapsedTime().asMilliseconds() < 12000 && enemyCount < 4)
		{
			currentEnemies[enemyCount] = EnemyShip(enemyTypes[1]);
			enemyCount++;
		}
		
		if (gameClock.getElapsedTime().asMilliseconds() > 20000)
		{
			gameClock.restart();
			enemyCount = 0;
		}
		


		if (checkFire())
		{
			//checks the shot clock to see if more time has passed than the current gun types fire delay value
			if (test.getFireDelay() < test.getTime())
			{

				currentProjectiles[projectileCount] = test.shoot();

				//creates shape objects for newly created projectiles
				//drawnShapes[projectileCount] = sf::CircleShape::CircleShape(currentProjectiles[projectileCount].getRadius());
				projectileCount++;


				//checks if number of currently active projectiles from player ship is at the array limit
				//resets the counter when it hits the limit so old array values are re written
				//will need to increase array size if more than 20 projectiles are required on the screen at once
				if (projectileCount > currentProjectiles.size() - 1)
				{
					projectileCount = 0;
				}
			}
		}

		for (int i = 0; i < maxEnemies - 1; i++)
		{
			if (currentEnemies[i].getFireDelay() < currentEnemies[i].getTime() && currentEnemies[i].getVisible())
			{
				enemyProjectiles[enemyProjectileCount] = currentEnemies[i].shoot();
				enemyProjectileCount++;

				if (enemyProjectileCount > enemyProjectiles.size() - 1)
				{
					enemyProjectileCount = 0;
				}
			}
		}


		test.move(cInput);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		{
			currentPlayerGun++;
			test.setGunType(playerArsenal[currentPlayerGun]);

			if (currentPlayerGun > 5)
			{
				currentPlayerGun = 0;
			}
		}



	
		window.clear();
		//window.draw(background);
		window.draw(test.updateObject());


		//updates and draws all player projectiles
		for (int i = 0; i < currentProjectiles.size(); i++)
		{
			for (int j = 0; j < maxEnemies; j++)
			{
				if (currentProjectiles[i].getVisible())
				{
					if (currentEnemies[j].hostileCollision(currentProjectiles[i]))
					{
						currentProjectiles[i].makeInvisible();
					}
				}
		
			}
			if (currentProjectiles[i].getVisible())
			{
				window.draw(currentProjectiles[i].updateProjectile());
			}

		}

		//updates and draws all visible enemy ships
		for (int i = 0; i < maxEnemies; i++)
		{
			if (currentEnemies[i].getVisible())
			{
				currentEnemies[i].move();
				window.draw(currentEnemies[i].updateObject());
			}

		}

		for (int i = 0; i < enemyProjectiles.size(); i++)
		{
			if (enemyProjectiles[i].getVisible())
			{
				window.draw(enemyProjectiles[i].updateProjectile());
			}
		}

		window.display();
	}

	return 0;
}
