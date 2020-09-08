#pragma once


struct velocity
{
	float xVel;
	float yVel;
};

struct gunType
{
	int damage;
	int fireDelay;
	velocity projectileVel;
	int projectileRadius;
};