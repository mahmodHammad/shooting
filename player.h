#pragma once
#include "entity.h"

#include<iostream>
#include<SFML\Graphics.hpp>

class player 	
{
private:
	sf::RenderWindow *Window;


	sf::RectangleShape mplayer;
	sf::RectangleShape gun;

	sf::Vector2f playerCenter;
	sf::Vector2f mousePosition;
	sf::Vector2f unitV;
	bool fire = false;

	float		 rotation;
	void init();


public:

	void setRenderWindow(sf::RenderWindow *window);
	void updateGun();
	void inputHandler();
	sf::Vector2f getGunPos();
	sf::Vector2f GetUnitV();
	sf::Vector2f cuv;
	//void fire(sf::Vector2f);
	bool getFire();
	player();
	~player();
	void update();
	void render();
	void setup();
};

