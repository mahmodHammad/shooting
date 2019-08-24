#pragma once
#include"Gun.h"
#include"InputHandler.h"

class player 	
{
private:
	enum keys { top, left, right, down, esc, enter, lclick, rclick };
	InputHandler keyhandler;

	sf::RenderWindow *Window;

	sf::RectangleShape mplayer;
	sf::Vector2f playerSize;
	float speed; 
	sf::Color defaultCOL;
	sf::Vector2f initialPostion;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosition;
	sf::Vector2f unitV;
	
	float dy;
	float dx;
	float rotation;
	Gun mygun;
	Gun otherGun;
	Gun otherGun1;
	Gun otherGun2;
	Gun otherGun3;
	Gun otherGun4;

	std::vector<Projectile* > projs;
	bool reload;
	int hits=0 ;
	
	void hit();
	void shoot();
	void reset();
	void setUnitVector();
	void updateAngle();
	void colide();
	void init();
	

public:
	void setinitpos(sf::Vector2f pos);
	void setRenderWindow(sf::RenderWindow *window);
	void inputHandler();
	player();
	~player();
	void update();
	void render();
};










