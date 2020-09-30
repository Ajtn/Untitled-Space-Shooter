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
	sf::CircleShape body;



	void updatePosition();

public:



	GameObject();

	//Used for projectile constructor
	GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius);

	GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius);

	float getYPos() const;

	float getXPos() const;

	bool getFriendly() const;

	bool getVisible() const;

	void setVel(velocity newVel);

	int getRadius() const;

	void makeInvisible();

	sf::CircleShape updateObject();

	void resizeObject();







};

