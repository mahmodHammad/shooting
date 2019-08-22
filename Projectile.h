#pragma once
#pragma message ("projectile object is defined")

#include<iostream>
#include<SFML\Graphics.hpp>
//#include"player.h"
class Projectile 
{
//inported variables----------------
//	bool fire; 
	sf::Vector2f direction; //will be const
	sf::Vector2f gunPosition; //will be updated
//----------------------------------

	sf::RenderWindow * window;
	sf::CircleShape ball;
	void beforeFire(sf::Vector2f pos);
 
public:
	Projectile(sf::RenderWindow* win , sf::Vector2f dir , sf::Vector2f gp);
	~Projectile();
	void init();


	void update();
	void afterFire(sf::Vector2f);
	
	
	void render();
};

