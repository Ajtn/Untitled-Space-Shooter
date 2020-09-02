#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
	visible = true;
	xPos = 0;
	yPos = 0;
	xVel = 0;
	yVel = 0;
	friendly = false;
}



GameObject::GameObject(int yP, int xP, int yV, int xV, bool iFriendly)
{
	yPos = yP;
	xPos = xP;
	yVel = yV;
	xVel = xV;

	friendly = iFriendly;

	visible = false;

}

void GameObject::updatePosition()
{
	yPos = yPos + yVel;
	xPos = xPos + xVel;
}

int GameObject::getYPos()
{
	return yPos;
}

int GameObject::getXPos()
{
	return xPos;
}

void GameObject::makeVisible()
{
	visible = true;
}

void GameObject::setYVel(int newYVel)
{
	std::wcout << newYVel;
	yVel = newYVel;
}


void GameObject::setXVel(int newXVel)
{
	xVel = newXVel;
}

/*
void GameObject::manualPosition(int givenXPos, int givenYPos)
{
	xPos = givenXPos;
	yPos = givenYPos;
}
*/