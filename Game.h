#pragma once
#include "EnemyShip.h"
#include "PlayerShip.h"
#include "Projectile.h"
#include "PowerUp.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
	//different instance of game could be called for each level with different arrays of available enemies, pathing, guns etc
	//the window could be passed as a parameter to the constructor to allow one window to be created for the entire session
	//playerShip should also be passed if playerShip state is continuous

private:
	//used to control how often enemies spawn
	sf::Clock spawnTimer;


	//array of currently loaded enemies
	EnemyShip enemies[10];

	//int to track most recently used value in enemies array
	int currentEnemy;

	//array to store all current enemy projectiles
	Projectile enemyShots[50];

	//int to track most recently used value in enemyShot array
	int currentEnemyShot;

	//array of all player projectiles
	Projectile playerShots[20];

	//int to track most recently used value in playerShots array
	int currentShot;

	//array of all current powerups
	//PowerUp powerUps[2];

	//ship controller by player
	PlayerShip player;

	//Array of all combinations of enemy values for movement, weapons, hp, and spawns. Hard coded values
	EnemyShip enemyTemplates[10];


	//image for the background of current level
	sf::Sprite background;

	void spawnEnemies();
	void enemiesShoot();
	void playerInput();
	void checkCollisions();
	void updateObjects(sf::RenderWindow& screen);

public:
	//window the game is visible in
	//sf::RenderWindow screen;

	//constructor for game with multiple worlds, may want to add enemyArsenal, and pathing so they can be different between worlds
	//texture will also need to be addded
	Game(EnemyShip thisWorldsEnemies[10], sf::Sprite initBackground);

	void run();
};

