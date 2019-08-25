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
	//sf::RectangleShape mplayer;
	//sf::Vector2f playerSize;
	//float speed; 
	//sf::Color defaultCOL;
	//sf::Vector2f initialPostion;
	//sf::Vector2f playerCenter;


	//sf::Vector2f mousePosition;
	//sf::Vector2f unitV;
	//
	//float dy;
	//float dx;
	//float rotation;
	//

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










