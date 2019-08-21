#include "Projectile.h"


void Projectile::init()
{
	ball.setFillColor(sf::Color::Magenta);
	ball.setRadius(10.1);
}

void Projectile::update(sf::Vector2f pos ,sf::Vector2f uv , bool fire)
{
	if (fire) {
		afterFire(uv);
	}
	else
		beforeFire(pos);
}

void Projectile::beforeFire(sf::Vector2f pos)
{
	float xx = pos.x - ball.getRadius() ;
	ball.setPosition(xx , pos.y - ball.getRadius());
}

void Projectile::afterFire(sf::Vector2f uv)
{
	ball.move(-uv);
}

Projectile::Projectile()
{
	init();
}


Projectile::~Projectile()
{
}


void Projectile::render()
{
	window->draw(ball);
}

void Projectile::setupWindow(sf::RenderWindow * win)
{
	window = win;
}
