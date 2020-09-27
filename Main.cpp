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
	//multi dimensional array of movement patterns for AI, velocity to be changed incrementally to make non linear movement
	//stores 8 arrays of 12 movements each
	velocity pathing[8][12] =
	{
		//0) accelerates right to left while slowly moving down
		{{s * 2, s * 1}, {s * 4, s * 1}, {s * 2, s * 1}, {0, s * 1}, {-s * 2, s * 1}, {-s * 4, s * 1}, {-s * 2, s * 1}, {0, s * 1}, {s * 2, s * 1}, {s * 4, s * 1}, {s * 2, s * 1}, {0, s * 1}},
		//1)
		{{s * 2, s * 2}, {s * 2, s * 4}, {s * 2, 0}, {-s * 2, -s * 2}, {-s * 2, -s * 4}, {-s * 2, -s * 2}, {s * 2, 0}, {s * 2, s * 2}, {s * 2, s * 4}, {s * 2, 0}, {s * 2, s * 2}, {s * 2, s * 4}},
		//2) moves left to right, comes in from right side of the screen (doesn't move vertically)
		{{-s * 2, 0}, {-s * 2, 0}, {-s * 2, 0}, {s * 2, 0}, {s * 2, 0}, {s * 2, 0}, {-s * 2, 0}, {-s * 2, 0}, {-s * 2, 0}, {s * 2, 0}, {s * 2, 0}, {s * 2, 0}},
		//3) shaped loop (recurrable)
		{{s * 1, s * 0.3}, {s * 0.866, s * 0.7}, {s * 0.5, s * 0.966}, {s * 0, s * 1}, {-s * 0.5, s * 0.866}, {-s * 0.866, s * 0.5}, {-s * 1, 0}, {-s * 0.866, -s * 0.5}, {-s * 0.5, -s * 0.866}, {0, -s * 1}, {s * 0.5, -s * 0.866}, {s * 0.866, -s * 0.5}},
		//4) moves up and down the screen moving to the right after each direction change
		{{0, s * 4}, {0, s * 4}, {s * 2, -s * 2}, {0, -s * 4}, {0, -s * 4}, {s * 2, s * 2}, {0, s * 4}, {0, s * 4}, {s * 2, -s * 2}, {0, -s * 4}, {0, -s * 4}, {s * 2, s * 2}},
		//5)
		{{s * 1, s * 1 }, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1 }, {s * 1, s * 1 }, {s * 1, s * 1}, {s * 1, s * 1}},
		//6)
		{{s * 1, s * 1 }, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}, {s * 1, s * 1}},
		//7)
		{{0, s * 1 }, {0, s * 1 }, {0, s * 1 }, {0, s * 1 }, {0, s * 1}, {0, s * 1}, {0, s * 1}, {0, s * 1}, {0, s * 1}, {0, s * 1}, {0, s * 1}, {0, s * 1}},
	};

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
		{pathing[2], enemyArsenal[0], 2, 1000, 0, false, 40},
		//1)
		{pathing[2], enemyArsenal[2], 2, 1000, 0, false, 40},
		//2)
		{pathing[0], enemyArsenal[0], 2, 500, 0, false, 40},
		//3)
		{pathing[2], enemyArsenal[0], 2, 1920, 0, false, 40 },
		//4)
		{pathing[3], enemyArsenal[0], 3, 500, 0, false, 40},
		//5
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30}
	};
	
	Game* gamePtr = new Game(enemyTypes);
	gamePtr->run();

	delete(gamePtr);

	return 0;
}
