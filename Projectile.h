#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<cstdlib>

class Projectile 
{
//inported variables----------------
	sf::CircleShape ball;
	sf::Vector2f direction;  
	sf::Vector2f gunPosition; 
//----------------------------------
	sf::RenderWindow * window;
	float  speed;
	
public:
	Projectile(sf::RenderWindow* win , sf::Vector2f dir , sf::Vector2f gp);
	~Projectile();
	void init();
	sf::Vector2f getBallCenter();
	void update();
	void afterFire();
	void render();
};