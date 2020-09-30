#include "GameObject.h"


void GameObject::updatePosition()
{
	//sets current position based on previous position + current velocity
	xPos = xPos + objectVelocity.xVel;
	yPos = yPos + objectVelocity.yVel;

	if (xPos > 1920 + 2 * getRadius()|| xPos < 0 - 2 * getRadius())
	{
		makeInvisible();
	}

	if (yPos > 1080 + 2 * getRadius() || yPos < 0 - 2 * getRadius())
	{
		makeInvisible();
		//std::cout << "out of bounds y" << std::endl;
	}
}

//loads this object's spritesheet using the address passed as a string
void GameObject::setSpriteSheet(std::string address)
{
	if (!spriteSheet.loadFromFile(address))
	{
		system("pause");
	}
}


//takes 4 int values as input to choose intended sprite from this object's spriteSheet
void GameObject::setSprite(int spriteSelect[4])
{

	body.setTexture(spriteSheet);
	body.setTextureRect(sf::IntRect(spriteSelect[0], spriteSelect[1], spriteSelect[2], spriteSelect[3]));
}


GameObject::GameObject()
{
	visible = false;
	xPos = 0;
	yPos = 0;
	objectVelocity.xVel = 0;
	objectVelocity.yVel = 0;
	friendly = false;
	radius = 1;
}



//Used for projectile constructor
GameObject::GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius,
	std::string spriteAddress, int initialSpriteSelect[4])
{
	xPos = initialX;
	yPos = initialY;

	objectVelocity = initialVelocity;

	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

	//sf::CircleShape tempShape(radius);

	//body = tempShape;

	//body.setFillColor(sf::Color::Red);

	setSpriteSheet(spriteAddress);

	setSprite(initialSpriteSelect);

	body.setPosition(xPos, yPos);

}



GameObject::GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius, std::string spriteAddress, int initialSpriteSelect[4])
{
	xPos = initialX;
	yPos = initialY;

	objectVelocity.xVel = 0;
	objectVelocity.xVel = 0;

	friendly = initialFriendly;

	visible = true;

	radius = initialRadius;

	//sf::CircleShape tempShape(radius);

	//body = tempShape;

	//body.setFillColor(sf::Color::Cyan);
	setSpriteSheet(spriteAddress);

	setSprite(initialSpriteSelect);

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

bool GameObject::getVisible() const
{
	return visible;
}

void GameObject::setVel(velocity newVel)
{
	objectVelocity = newVel;
}

int GameObject::getRadius() const
{
	return radius;
}

void GameObject::makeInvisible()
{
	visible = false;
}

sf::Sprite GameObject::updateObject()
{
	//returns the shape value to be drawn onto screen

	updatePosition();
	body.setPosition(xPos, yPos);
	return body;

}

void GameObject::resizeObject()
{

	//body.setRadius(radius);
	//body.setFillColor(sf::Color::Cyan);
	visible = true;
}


