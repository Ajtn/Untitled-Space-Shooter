#include "GameObject.h"


void GameObject::updatePosition()
{

	xPos = xPos + objectVelocity.xVel;
	yPos = yPos + objectVelocity.yVel;

}

void GameObject::makeVisible()
{
	visible = true;
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



//Used foor projectile constructor
GameObject::GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius)
{
	xPos = initialX;
	yPos = initialY;

	objectVelocity = initialVelocity;

	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

	sf::CircleShape tempShape(radius);

	body = tempShape;

	body.setFillColor(sf::Color::Red);

	body.setPosition(xPos, yPos);

}



GameObject::GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius)
{
	xPos = initialX;
	yPos = initialY;

	objectVelocity.xVel = 0;
	objectVelocity.xVel = 0;

	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

	sf::CircleShape tempShape(radius);

	body = tempShape;

	body.setFillColor(sf::Color::Cyan);

	body.setPosition(xPos, yPos);

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


void GameObject::setVel(velocity newVel)
{
	objectVelocity = newVel;
}

int GameObject::getRadius() const
{
	return radius;
}


sf::CircleShape GameObject::updateObject()
{
	updatePosition();
	body.setPosition(xPos, yPos);
	return body;

}
