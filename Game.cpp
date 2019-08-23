#include "game.h"
#include <cmath>

void game::init()
{	
	window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode()), "my Duck Attack");
	window->setVerticalSyncEnabled(true);
	window->setMouseCursorVisible(true);
	window->setKeyRepeatEnabled(false);
	mplayer.setRenderWindow(window);
	mplayer.setup();
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
	mplayer.setRenderWindow(window);
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
	//entity.update();
}

void game::render()
{
	window->clear();
	mplayer.render();
//	entity.render();
	window->display();
}

