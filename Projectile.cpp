#include "Projectile.h"


Projectile::Projectile(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly, int initialDamage, int initialRadius)
	:GameObject(initialX, initialY, initialXVel, initialYVel, initialFriendly, initialRadius)
{
	damage = initialDamage;

}

Projectile::Projectile()
{
	damage = 1;

}
