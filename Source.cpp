#include"game.h"

int main()
{
	sf::err().rdbuf(NULL);
	game g;
	g.run();
	return 0;
}