#include "Projectile.h"

void Projectile::init()
{
	ball.setFillColor(sf::Color::Green);
	ball.setRadius(3.1);
	speed = 2;
}

sf::Vector2f Projectile::getBallCenter()
{
	return ball.getPosition();
}

void Projectile::update()
{
		afterFire();
}

void Projectile::afterFire()
{
	if (ball.getPosition().x <= 1 || ball.getPosition().x >= window->getSize().x)
		direction.x *= -1;
	if (ball.getPosition().y <= 1 || ball.getPosition().y >= window->getSize().y)
		direction.y *= -1;
		ball.move( direction.x *speed, direction.y*speed);
}

Projectile::Projectile(sf::RenderWindow* win ,sf::Vector2f dir ,sf::Vector2f gp):window(win),direction(-dir), gunPosition(gp)
{
	init();
	ball.setPosition(gp.x - ball.getRadius(), gp.y - ball.getRadius());
}

Projectile::~Projectile()
{
}

void Projectile::render()
{
	window->draw(ball);
}

