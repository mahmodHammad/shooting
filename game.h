#pragma once
#include"Projectile.h"
#include"player.h"

class game
{

private:

	void init();
	sf::RenderWindow *window;
	sf::Event event;
	player mplayer;
	player oplayer;

	player aplayer;
	player splayer;

	player fplayer;
	player gplayer;
	

public:
	game();
	~game();
	void run();
	void update();
	void updateSFMLevents();
	void render();
};

