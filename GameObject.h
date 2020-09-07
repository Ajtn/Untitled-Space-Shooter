#pragma once
#include "Structs.h"

class GameObject
{
private:
	bool visible;
	float xPos;
	float yPos;
	//float xVel;
	//float yVel;
	velocity objectVelocity;
	bool friendly;

	//initial build will use circle based hit boxes, may swap to sprite based later
	int radius;



	//void updatePosition();

	void makeVisible();

	bool collision(float otherObjectX, float otherObjectY, int otherObjRadius);

public:

	//temporarily public for test
	void updatePosition();

	GameObject();

	GameObject(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialRadius);

	GameObject(float initialX, float initialY, bool initialFriendly, int initialRadius);

	float getYPos() const;

	float getXPos() const;

	bool getFriendly() const;

	void setYVel(float newYVel);

	void setXVel(float newXVel);

	int getRadius() const;





};

