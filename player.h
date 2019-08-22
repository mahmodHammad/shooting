#pragma once
#pragma message ("player object is defined")
#include "entity.h"
#include"Projectile.h"
#include<iostream>
#include<SFML\Graphics.hpp>

class player 	
{
private:
	sf::RectangleShape mplayer;
	std::vector<Projectile* > projs;
	int speed; 
	bool reload;

protected:
	sf::RenderWindow *Window;
	sf::RectangleShape gun;
	 float		 rotation;
	void init();
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosition;
	sf::Vector2f unitV;
	bool fire = false;

	void colide();


public:

	void setRenderWindow(sf::RenderWindow *window);
	void updateGun();
	void inputHandler();
	sf::Vector2f getGunPos();
	sf::Vector2f cuv;
	player();
	~player();
	void update();
	void render();
	void setup();
};

