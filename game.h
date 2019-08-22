#pragma once
#include"Projectile.h"
#include"player.h"
class game
{public:
	void updateevents();
	void run();
	void update();
	void render();
	game();
	~game();

private:

	void init();
	sf::RenderWindow *window;
	sf::Event event;

	player mplayer;

 


};

