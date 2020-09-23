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
	//multi dimensional array of movement patterns for AI, velocity to be changed incrementally to make non linear movement
	//stores 8 arrays of 12 movements each
	velocity pathing[8][12] =
	{
		//0) accelerates right to left while slowly moving down
		{{0.25, 0.125}, {0.5, 0.125}, {0.25, 0.125}, {0, 0.125}, {-0.25, 0.125}, {-0.5, 0.125}, {-0.25, 0.125}, {0, 0.125}, {0.25, 0.125}, {0.5, 0.125}, {0.25, 0.125}, {0, 0.125}},
		//1)
		{{0.25, 0.25}, {0.25, 0.5}, {0.25, 0}, {-0.25, -0.25}, {-0.25, -0.5}, {-0.25, -0.25}, {0.25, 0}, {0.25, 0.25}, {0.25, 0.5}, {0.25, 0}, {0.25, 0.25}, {0.25, 0.5}},
		//2) moves left to right, comes in from right side of the screen (doesn't move vertically)
		{{-0.25, 0}, {-0.25, 0}, {-0.25, 0}, {0.25, 0}, {0.25, 0}, {0.25, 0}, {-0.25, 0}, {-0.25, 0}, {-0.25, 0}, {0.25, 0}, {0.25, 0}, {0.25, 0}},
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
		{pathing[3], enemyArsenal[0], 2, 500, 0, false, 40},
		//5
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30},
		{pathing[4], enemyArsenal[1], 2, 500, 0, false, 30}
	};
	
	Game game = Game(enemyTypes);
	game.run();


	return 0;
}
