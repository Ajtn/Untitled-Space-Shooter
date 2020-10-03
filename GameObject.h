#pragma once
#include "Structs.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
private:
	bool visible;
	float xPos;
	float yPos;
	velocity objectVelocity;
	bool friendly;

	//initial build will use circle based hit boxes, may swap to sprite based later
	int radius;

	//initial build will draw everything as circles
	//sf::CircleShape body;

	sf::Sprite body;

	sf::Texture spriteSheet;



	void updatePosition();

	void setSpriteSheet(std::string address);

protected:
	void setSprite(sf::Rect<int> selectedSprite);

public:



	GameObject();

	//Used for projectile constructor
	GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius,
		std::string spriteAddress, sf::Rect<int> initialSelectedSprite);

	GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius, std::string spriteAddress, sf::Rect<int> initialSelectedSprite);

	float getYPos() const;

	float getXPos() const;

	bool getFriendly() const;

	bool getVisible() const;

	void setVel(velocity newVel);

	int getRadius() const;

	void makeInvisible();

	sf::Sprite updateObject();

	void resizeObject();








};

