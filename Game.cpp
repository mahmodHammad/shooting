#include "game.h"
#include <cmath>

void game::init()
{	
	window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode()), "my Duck Attack");
	window->setVerticalSyncEnabled(false);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(true);
//	window->setKeyRepeatEnabled(false);

	mplayer.setinitpos(sf::Vector2f(800, 90));
	mplayer.setRenderWindow(window);
	mplayer.setup();

	oplayer.setinitpos(sf::Vector2f(200, 90));
	oplayer.setRenderWindow(window);
	oplayer.setup();

	aplayer.setinitpos(sf::Vector2f(200, 600));
	aplayer.setRenderWindow(window);
	aplayer.setup();

	splayer.setinitpos(sf::Vector2f(800,400));
	splayer.setRenderWindow(window);
	splayer.setup();

	fplayer.setinitpos(sf::Vector2f(400, 600));
	fplayer.setRenderWindow(window);
	fplayer.setup();

	gplayer.setinitpos(sf::Vector2f(800, 600));
	gplayer.setRenderWindow(window);
	gplayer.setup();
}

void game::updateSFMLevents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}

game::game()
{
	init();
}


game::~game()
{
	delete window;
}


void game::update()
{
	updateSFMLevents();
	mplayer.update();
	oplayer.update();
	aplayer.update();
	splayer.update();
	fplayer.update();
	gplayer.update();
	//entity.update();
}

void game::render()
{
	window->clear();
	mplayer.render();
	oplayer.render();
	aplayer.render();
	splayer.render();
	fplayer.render();
	gplayer.render();
//	entity.render();
	window->display();
}

