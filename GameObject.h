#pragma once
class GameObject
{
private:
	bool visible;
	int xPos;
	int yPos;
	int xVel;
	int yVel;
	bool friendly;

	//initial build will use circle based hit boxes, may swap to sprite based later
	int radius;



	//void updatePosition();

	void makeVisible();

	bool collision(int otherObjectX, int otherObjectY, int otherObjRadius);

public:

	//temporarily public for test
	void updatePosition();

	GameObject();

	GameObject(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly, int initialRadius);

	int getYPos() const;

	int getXPos() const;

	bool getFriendly() const;

	void setYVel(int newYVel);

	void setXVel(int newXVel);

	int getRadius() const;





};

