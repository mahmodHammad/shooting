#pragma once
#include"Entity.h"
#include"SFML\Graphics.hpp"

class game
{
private:
	void init();
	sf::RenderWindow *window;
	sf::Event event;
	Entity entity;

public:
	game();
	~game();
	void run();
	void update();
	void updateSFMLevents();
	void render();
};

