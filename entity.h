#pragma once
#include"InputHandler.h"
#include"Player.h"
class Entity 	
{
private:
	enum keys { top, left, right, down, esc, enter, lclick, rclick };
	InputHandler keyhandler;
	Player *mplayer;
	Player * aplayer;
	Player * fplayer;
	Player * gplayer;
	std::vector<Player * > players;
	sf::RenderWindow *Window;
	std::vector<Projectile* > projs;
	bool reload;
	void shoot();
	void reset();
	void restart();
	void colide(int i, Player* plyer );
	void colitionDetection(Player* player);
	void init();
	void gameover();

public:
	void setRenderWindow(sf::RenderWindow *window);
	void inputHandler();
	Entity();
	~Entity();
	void update();
	void render();
};










