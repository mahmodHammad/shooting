#include "game.h"

void game::init()
{	
	window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode()), "my Duck Attack");
	window->setVerticalSyncEnabled(false);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(true);
//	window->setKeyRepeatEnabled(false);
	mplayer.setinitpos(sf::Vector2f(800, 90));
	mplayer.setRenderWindow(window);

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

}

void game::render()
{
	window->clear();
	mplayer.render();

	window->display();
}

