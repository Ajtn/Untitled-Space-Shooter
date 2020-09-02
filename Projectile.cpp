#include "Projectile.h"


Projectile::Projectile(int initialX, int initialY, int initialXVel, int initialYVel, bool initialFriendly, int initialDamage)
{
	GameObject(initialX, initialY, initialXVel, initialYVel, initialFriendly);
	damage = initialDamage;

}
