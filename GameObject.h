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


	//void updatePosition();

	void makeVisible();

public:

	//temporarily public for test
	void updatePosition();

	GameObject();

	GameObject(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly);

	int getYPos() const;

	int getXPos() const;

	bool getFriendly() const;

	void setYVel(int newYVel);

	void setXVel(int newXVel);




};

