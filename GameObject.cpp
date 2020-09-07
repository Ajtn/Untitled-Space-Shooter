#include "GameObject.h"
#include <iostream>


void GameObject::makeVisible()
{
	visible = true;
}

bool GameObject::collision(int otherObjectX, int otherObjectY, int otherObjRadius)
{
	if (abs(xPos - otherObjectX) < (radius + otherObjRadius))
	{
		if (abs(yPos - otherObjectY) < (radius + otherObjRadius))
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

GameObject::GameObject()
{
	visible = true;
	xPos = 0;
	yPos = 0;
	xVel = 0;
	yVel = 0;
	friendly = false;
	radius = 1;
}



GameObject::GameObject(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly, int initialRadius)
{
	xPos = initialX;
	yPos = initialY;
	xVel = initialXVel;
	yVel = initialYVel;

	std::wcout << "xPos = ";
	std::wcout << xPos;

	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

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


void GameObject::setYVel(int newYVel)
{
	yVel = newYVel;
}


void GameObject::setXVel(int newXVel)
{
	xVel = newXVel;
}

int GameObject::getRadius() const
{
	return radius;
}

/*
void GameObject::manualPosition(int givenXPos, int givenYPos)
{
	xPos = givenXPos;
	yPos = givenYPos;
}
*/