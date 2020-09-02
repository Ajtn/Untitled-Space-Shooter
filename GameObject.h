#pragma once
class GameObject
{
private:
	bool visible;
	int yPos;
	int xPos;
	int yVel;
	int xVel;
	bool friendly;


	//void updatePosition();

	void makeVisible();

public:

	//temporarily public for test
	void updatePosition();

	GameObject();

	GameObject(int yP, int xP, int yV, int xV, bool iFriendly);

	int getYPos();

	int getXPos();

	void setYVel(int newYVel);

	void setXVel(int newXVel);


	//virtual void updateState();

	//void manualPosition(int givenXPos, int givenYPos);



};

