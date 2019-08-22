#include "Projectile.h"

void Projectile::init()
{
	ball.setFillColor(sf::Color::Green);
	ball.setRadius(7.1);
	speed = 6;
}

void Projectile::update()
{
		afterFire();
		colide();
}

void Projectile::afterFire()
{
	if (ball.getPosition().x <= 1 || ball.getPosition().x >= window->getSize().x)
		direction.x *= -1;
	if (ball.getPosition().y <= 1 || ball.getPosition().y >= window->getSize().y)
		direction.y *= -1;
		ball.move( direction.x *speed, direction.y*speed);

}

void Projectile::colide()
{

}

Projectile::Projectile(sf::RenderWindow* win ,sf::Vector2f dir ,sf::Vector2f gp):window(win),direction(-dir), gunPosition(gp)
{
	init();
	ball.setPosition(gp.x - ball.getRadius(), gp.y - ball.getRadius());
	//window->draw(ball);
}

Projectile::~Projectile()
{
}


void Projectile::render()
{
	window->draw(ball);
}

