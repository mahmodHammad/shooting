#include"Gun.h"

class Player
{
private:
	sf::RectangleShape mplayer;
	sf::RenderWindow *window;

	sf::Vector2f playerSize;
	float speed;
	sf::Color defaultCOL;
	sf::Vector2f initialPostion;
	sf::Vector2f playerCenter;
	sf::Vector2f GunHolePosition;


	Gun mygun;
	sf::Vector2f mousePosition;
	sf::Vector2f unitV;
	float dy;
	float dx;
	float rotation;

	int hits;
	void init();
	void updateAngle();


public:
	Player();
	Player(sf::RenderWindow *window, sf::Vector2f inposition, sf::Vector2f size
		,sf::Color Defcolr=sf::Color::Red ,float speed=.3);
	~Player();
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::Vector2f GetDirection();
	sf::Vector2f GetGunHolePosition();
	void setupPlayer(sf::RenderWindow *window, sf::Vector2f initialPosition);
	void hit();
	void reset();
	void Move(int x, int y);
	void updatevectors();
	void update();
	void render();



};
