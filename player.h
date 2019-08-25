#include"Gun.h"

class Player
{
private:
	sf::RectangleShape mplayer;
	sf::RenderWindow *Window;

	sf::Vector2f playerSize;
	float speed;
	sf::Color defaultCOL;
	sf::Vector2f initialPostion;
	sf::Vector2f playerCenter;
	//std::vector<sf::Vector2f> GetGunHolePosition();
	std::vector < sf::Vector2f>gunposs;

	Gun mygun;
	Gun aygun;
	Gun sygun;
	std::vector<Gun> guns;
	sf::Vector2f mousePosition;
	sf::Vector2f unitV;
	float dy;
	float dx;
	float rotation;

	int hits;
	void updateAngle();


public:
	Player();
	Player(sf::RenderWindow *window, sf::Vector2f inposition, sf::Vector2f size
		,sf::Color Defcolr=sf::Color::Red ,float speed=.3);
//	~Player();
	int  getHits();
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::Vector2f GetDirection();
	std::vector<sf::Vector2f> GetGunHolePosition();
	void hit();
	void reset();
	void Move(int x, int y);
	void updatevectors();
	void update();
	void render();



};
