#pragma once
#include"States.h"
#include"entity.h"

class game
{
private:

	void init();
	sf::RenderWindow *window;
	sf::Event event;


	sf::RectangleShape player;
	sf::RectangleShape gun;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosition;
	float		 rotation;


public:
	void updateGun();
	void updateevents();
	void run();
	void update();
	void render();
	game();
	~game();

};

