#include "Pathing.h"

Pathing::Pathing(velocity inRecurringVel[12], velocity inEntryVel)
{
	for (int i = 0; i < 12; i++)
	{
		recurringVel[i] = inRecurringVel[i];
	}

	entryVel = inEntryVel;

	useEntry = true;

	counter = 0;
}

Pathing::Pathing(velocity inRecurringVel[12])
{
	for (int i = 0; i < 12; i++)
	{
		recurringVel[i] = inRecurringVel[i];
	}

	entryVel = { 0, 0 };

	useEntry = false;

	counter = 0;
}

velocity Pathing::getVelocity()
{


	if (useEntry)
	{
		return entryVel;
		counter++;
		if (counter > 2)
		{
			counter = 0;
			useEntry = false;
		}
	}
	else
	{
		return recurringVel[counter];
		counter++;
		if (counter > 11)
		{
			counter = 0;
		}
	}
}