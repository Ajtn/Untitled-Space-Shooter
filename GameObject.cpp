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



GameObject::GameObject(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly)
{
	xPos = initialX;
	yPos = initialY;
	xVel = initialXVel;
	yVel = initialYVel;

	friendly = initialFriendly;

	visible = true;

}

void GameObject::updatePosition()
{
	yPos = yPos + yVel;
	xPos = xPos + xVel;
}

int GameObject::getYPos() const
{
	return yPos;
}

int GameObject::getXPos() const
{
	return xPos;
}

bool GameObject::getFriendly() const
{
	return friendly;
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