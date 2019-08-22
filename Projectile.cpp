#include "Projectile.h"


void Projectile::init()
{
	ball.setFillColor(sf::Color::Magenta);
	ball.setRadius(10.1);
}


//ssssssssssssssssssssssssssssssssssssssssssss
void Projectile::update()
{
	/*if (fire) {
		afterFire(this->direction);
	}*/
	//else
		beforeFire(this->gunPosition);
		//afterFire(this->direction);
}

void Projectile::beforeFire(sf::Vector2f pos)
{
	ball.setPosition(pos.x - ball.getRadius(), pos.y - ball.getRadius());
}


//ssssssssssssssssssssssssssssssssssssssssssssss

void Projectile::afterFire(sf::Vector2f uv)
{
	ball.move(-direction);
}


Projectile::Projectile(sf::RenderWindow* win ,sf::Vector2f dir ,sf::Vector2f gp):window(win),direction(dir), gunPosition(gp)
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

