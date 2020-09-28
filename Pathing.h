#pragma once
#include "Structs.h"

class Pathing
{
private:
	//core set of velocity values that object will follow and repeat
	velocity recurringVel[12];

	//optional set of velocity values that the object will follow once as it enters onto the screen
	velocity entryVel;

	bool useEntry;

	//counter keeps track of what part of the array was last used to return the values sequentially
	int counter;
public:
	Pathing(velocity inRecurringVel[12], velocity inEntryVel);

	Pathing(velocity inRecurringVel[12]);

	Pathing();

	velocity getVelocity();

};