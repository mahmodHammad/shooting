#pragma once
#include"Gun.h"

class player 	
{
private:
	sf::RectangleShape mplayer;
	Gun mygun;
	Gun otherGun;
	Gun otherGun1;
	Gun otherGun2;
	Gun otherGun3;
	Gun otherGun4;

	sf::Vector2f playerSize;
	float dy;
	float dx;
	std::vector<Projectile* > projs;
	sf::Color defaultCOL;
	float speed; 
	bool reload;
	int hits=0 ;
	void hit();
	void reset();
	sf::Vector2f initialPostion;
	void shoot();
	void setUnitVector();
	void updateAngle();

protected:
	void colide();
	sf::RenderWindow *Window;
	sf::RectangleShape gun;
	 float		 rotation;
	void init();
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosition;
	sf::Vector2f unitV;
	bool fire = false;



public:

	void setRenderWindow(sf::RenderWindow *window);
	void inputHandler();
	sf::Vector2f cuv;
	player();
	~player();
	void update();
	void render();
	void setup();
};

