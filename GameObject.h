#pragma once
#include "Structs.h"
#include <SFML/Graphics.hpp>

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

	void makeVisible();


public:



	GameObject();

	//Used foor projectile constructor
	GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius);

	GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius);

	float getYPos() const;

	float getXPos() const;

	bool getFriendly() const;

	void setVel(velocity newVel);

	int getRadius() const;


	sf::CircleShape updateObject();

	bool collision(float otherObjectX, float otherObjectY, int otherObjRadius);





};

