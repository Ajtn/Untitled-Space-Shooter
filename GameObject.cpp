#include "GameObject.h"
#include <iostream>


void GameObject::makeVisible()
{
	visible = true;
}

bool GameObject::collision(float otherObjectX, float otherObjectY, int otherObjRadius)
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
	objectVelocity.xVel = 0;
	objectVelocity.yVel = 0;
	friendly = false;
	radius = 1;
}



GameObject::GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius)
{
	xPos = initialX;
	yPos = initialY;
	objectVelocity = initialVelocity;
	//xVel = initialXVel;
	//yVel = initialYVel;


	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

}

GameObject::GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius)
{
	xPos = initialX;
	yPos = initialY;

	velocity initialVelocity;
	initialVelocity.xVel = 0;
	initialVelocity.yVel = 0;

	objectVelocity = initialVelocity;

	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

}

void GameObject::updatePosition()
{
	xPos = xPos + objectVelocity.xVel;
	yPos = yPos + objectVelocity.yVel;
}

float GameObject::getYPos() const
{
	return yPos;
}

float GameObject::getXPos() const
{
	return xPos;
}

bool GameObject::getFriendly() const
{
	return friendly;
}


void GameObject::setYVel(float newYVel)
{
	objectVelocity.yVel = newYVel;
}


void GameObject::setXVel(float newXVel)
{
	objectVelocity.xVel = newXVel;
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