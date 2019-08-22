#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>

class Projectile 
{
//inported variables----------------
	sf::Vector2f direction;  
	sf::Vector2f gunPosition; 
//----------------------------------
	sf::RenderWindow * window;
	sf::CircleShape ball;
	float  speed;
	
public:
	Projectile(sf::RenderWindow* win , sf::Vector2f dir , sf::Vector2f gp);
	~Projectile();
	void init();

	void update();
	void afterFire();
	void colide();

	void render();
};

