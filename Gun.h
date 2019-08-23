#pragma once
#include<iostream>
#include"Projectile.h"
#include<SFML\Graphics.hpp>

class Gun
{
private:
	sf::RenderWindow*	window;
	sf::RectangleShape  myGun;
	sf::Color			color;
	sf::Vector2f		position;
	sf::Vector2f		size;
	sf::Vector2f		origin;
	sf::Vector2f		unitVector;
	float				rotaion;
	int					indleft;
	int					indTop;
	//void initvar();
	void initGun();
public:
	Gun();
	~Gun();

	void setUpGun(sf::RenderWindow * window, sf::Color col = sf::Color::Yellow,
		sf::Vector2f size = sf::Vector2f(5, 70), 
		int positionleft = 1, int positiontop = 1);

	void update(sf::Vector2f positon, float rotaion, sf::Vector2f unitvect);
	void updateGun();
	void render();
	sf::Vector2f getGunPos();

};

