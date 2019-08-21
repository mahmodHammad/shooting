#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
class Projectile
{
	sf::RenderWindow * window;
	sf::CircleShape ball;
	void beforeFire(sf::Vector2f pos);
public:
	void setupWindow(sf::RenderWindow* win);
	Projectile();
	~Projectile();
	void init();
	void update(sf::Vector2f ,sf::Vector2f , bool);
	void afterFire(sf::Vector2f);
	void render();
};

