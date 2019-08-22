#pragma once
#include"Projectile.h"
#include"player.h"
class game
{
private:

	void init();
	sf::RenderWindow *window;
	sf::Event event;
	
	Projectile proj;
	player mplayer;

public:
	void updateevents();
	void run();
	void update();
	void render();
	game();
	~game();

};

