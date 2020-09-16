#pragma once
#include "EnemyShip.h"
#include "PlayerShip.h"
#include "Projectile.h"
#include "PowerUp.h"

class Game
{

private:
	sf::Clock spawnTimer;
	sf::Window screen;
	EnemyShip enemies[10];
	Projectile enemyShots[50];
	Projectile playerShots[20];
	//PowerUp powerUps[2];
	PlayerShip player;

	gunType playerArsenal[8];
	gunType enemyArsenal[5];

	EnemyShip enemyTemplates[10];

	void spawnObjects();
	void updateObjects();
	void checkCollisions();
	void drawObjects();
};

