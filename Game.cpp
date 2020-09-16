#include "Game.h"

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