#include "game.h"
#include <cmath>

void game::init()
{	
	window = new sf::RenderWindow(sf::VideoMode(860,620), "my Duck Attack");
	window->setVerticalSyncEnabled(true);
	window->setMouseCursorVisible(false);

	proj.setupWindow(window);
	mplayer.setRenderWindow(window);
	mplayer.setup();
}



void game::updateevents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	
}

void game::run()
{
	sf::err().rdbuf(NULL);
	while (window->isOpen())
	{
		update();
		render();
	}
}

void game::update()
{
	updateevents();
	mplayer.update();
	proj.update(mplayer.getGunPos() ,mplayer.GetUnitV() ,mplayer.getFire());
}

void game::render()
{
	window->clear();

	mplayer.render();
	proj.render();

	window->display();
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

