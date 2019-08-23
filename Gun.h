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
	sf::Vector2f		shiftposition;
	sf::Vector2f		size;
	sf::Vector2f		playersize;
	sf::Vector2f		origin;
	sf::Vector2f		unitVector;
	float				rotaion;
	int					indleft; // 0 left  1   2
	int					indTop; //  0 top   1   2
	//void initvar();
	void initGun();
	void shiftPos();
public:
	Gun();
	~Gun();

	void setUpGun(sf::RenderWindow * window, int positionleft , int positiontop ,
		sf::Vector2f playersize ,sf::Color col = sf::Color::Yellow,
		sf::Vector2f size = sf::Vector2f(5, 110));

	void update(sf::Vector2f positon, float rotaion, sf::Vector2f unitvect);
	void updateGun();
	void render();
	sf::Vector2f getGunPos();

};

