#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include"player.h"
class Projectile :public player
{
	sf::RenderWindow * window;
	sf::CircleShape ball;
	void beforeFire(sf::Vector2f pos);
	sf::Vector2f direction;
public:
	Projectile(sf::RenderWindow* win , sf::Vector2f dir);
	~Projectile();
	void init();


	void update();
	void afterFire(sf::Vector2f);
	
	
	void render();
};

