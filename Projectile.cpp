#include "Projectile.h"


Projectile::Projectile(float initialX, float initialY, velocity initialVelocity, bool initialFriendly, int initialDamage, int initialRadius)
	:GameObject(initialX, initialY, initialVelocity, initialFriendly, initialRadius, "Res/spritesheets/explosion.png", sf::Rect<int> (31, 1, 14, 14))
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

