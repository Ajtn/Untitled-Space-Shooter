#include <array>
#include "GameObject.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Structs.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
	//s is the coefficient for ship speed to easily 
	const float s = 5;

	//0) accelerates right to left while slowly moving down
	velocity pathing1[12] = { {s * 2, s * 1}, {s * 4, s * 1}, {s * 2, s * 1}, {0, s * 1}, {-s * 2, s * 1}, {-s * 4, s * 1}, {-s * 2, s * 1}, {0, s * 1},
		{s * 2, s * 1}, {s * 4, s * 1}, {s * 2, s * 1}, {0, s * 1} };

	//1)
	velocity pathing2[12] = { {s * 2, s * 2}, { s * 2, s * 4 }, { s * 2, 0 }, { -s * 2, -s * 2 }, { -s * 2, -s * 4 }, { -s * 2, -s * 2 }, { s * 2, 0 },
		{ s * 2, s * 2 }, { s * 2, s * 4 }, { s * 2, 0 }, { s * 2, s * 2 }, { s * 2, s * 4 } };

	//2) moves left to right, comes in from right side of the screen (doesn't move vertically)
	velocity pathing3[12] = { {-s * 2, 0}, { -s * 2, 0 }, { -s * 2, 0 }, { s * 2, 0 }, { s * 2, 0 }, { s * 2, 0 }, { -s * 2, 0 }, { -s * 2, 0 }, { -s * 2, 0 },
		{ s * 2, 0 }, { s * 2, 0 }, { s * 2, 0 } };

	//3) circle loop (recurrable)
	velocity pathing4[12] = { {s * 1, s * 0.15}, { s * 0.866, s * 0.65 }, { s * 0.5, s * 1 }, { s * 0, s * 1.15 }, { -s * 0.5, s * 1 },{ -s * 0.866, s * 0.65 },
		{ -s * 1, s * 0.15 }, { -s * 0.866, -s * 0.35 }, { -s * 0.5, -s * 0.716 }, { 0, -s * 0.85 }, { s * 0.5, -s * 0.716 }, { s * 0.866, -s * 0.35 }};

	//4) moves up and down the screen moving to the right after each direction change
	velocity pathing5[12] = {{0, s * 4}, { 0, s * 4 }, { s * 2, -s * 2 }, { 0, -s * 4 }, { 0, -s * 4 }, { s * 2, s * 2 }, { 0, s * 4 }, { 0, s * 4 },
		{ s * 2, -s * 2 }, { 0, -s * 4 }, { 0, -s * 4 }, { s * 2, s * 2 }};

	//5)
	velocity pathing6[12] = {{s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 },
		{ s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }};

	//6)
	velocity pathing7[12] = {{s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 },
		{ s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }, { s * 1, s * 1 }};

	//7)
	velocity pathing8[12] = {{0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 },
		{ 0, s * 1 }, { 0, s * 1 }, { 0, s * 1 }};


	//bs is the constant for bullet speed to easily modify all values
	const float bs = 20;
	//Array of all enemy guns (damage, fireDelay, (xVelocity, yVelocity), projectileRadius)
	gunType enemyArsenal[6] =
	{
		//0) basic small, low damage, slow shot
		{1, 500, {0, bs}, 8},
		//1) slightly high frequency
		{1, 350, {0, bs }, 8 },
		//2) double damage 
		{2, 500, {0, bs}, 8},
		//3) big bois
		{1, 500, {0, bs}, 16},
		//4) fast and frequent
		{1, 300, {0, bs}, 8},
		//5 nothing
		{0, 10000, {0, 0}, 0}
	};

	//Array of types of enemy ships (pathing, gunType, hp, xPos, yPos, friendly, radius)
	EnemyShip enemyTypes[10] =
	{
		//0)
		{Pathing(pathing1), enemyArsenal[0], 2, 1000, 0, false, 40},
		//1)
		{Pathing(pathing4), enemyArsenal[2], 2, 1000, 0, false, 40},
		//2)
		{Pathing(pathing5), enemyArsenal[0], 2, 500, 0, false, 50},
		//3)
		{Pathing(pathing2), enemyArsenal[0], 2, 1920, 0, false, 40 },
		//4)
		{Pathing(pathing1), enemyArsenal[0], 3, 500, 0, false, 40},
		//5
		{Pathing(pathing3), enemyArsenal[1], 2, 500, 0, false, 30},
		{Pathing(pathing1), enemyArsenal[1], 2, 500, 0, false, 30},
		{Pathing(pathing1), enemyArsenal[1], 2, 500, 0, false, 30},
		{Pathing(pathing1), enemyArsenal[1], 2, 500, 0, false, 30},
		{Pathing(pathing1), enemyArsenal[1], 2, 500, 0, false, 30}
	};
	
	Game* gamePtr = new Game(enemyTypes);
	gamePtr->run();

	delete(gamePtr);

	return 0;
}
