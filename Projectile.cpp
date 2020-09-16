#include "Projectile.h"


Projectile::Projectile(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialDamage, int initialRadius)
	:GameObject(initialX, initialY, initialVelocity, initialFriendly, initialRadius)
{
	damage = initialDamage;

}

Projectile::Projectile()
{
	damage = 0;

}

int Projectile::getDamage() const
{
	return damage;
}


sf::CircleShape Projectile::updateProjectile()
{
	if (getFriendly())
	{
		if (getYPos() <= 0 + getRadius())
		{
			makeInvisible();
		}
	}
	else
	{
		if (getYPos() >= 1080 - getRadius())
		{
			makeInvisible();
		}
	}

	return updateObject();
}