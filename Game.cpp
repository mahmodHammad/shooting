#include "game.h"
#include <cmath>

void game::init()
{	
	window = new sf::RenderWindow(sf::VideoMode(860,620), "my Duck Attack");
	window->setVerticalSyncEnabled(true);

	player.setFillColor(sf::Color::Red);
	player.setSize(sf::Vector2f(150,50));
	player.setPosition(window->getSize().x/2 -player.getSize().x /2 , window->getSize().y  - player.getSize().y);
	//player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);  FIX IT LATER

	gun.setFillColor(sf::Color::Yellow);
	gun.setSize(sf::Vector2f(5, 70));
	gun.setOrigin(gun.getSize().x / 2, gun.getSize().y);
}


void game::updateGun()
{
	playerCenter = sf::Vector2f(player.getPosition().x + player.getSize().x / 2, player.getPosition().y + player.getSize().y / 2);
	gun.setPosition(playerCenter);
	float dy =  playerCenter.y- mousePosition.y;
	float dx = -(playerCenter.x -mousePosition.x );
	float angle = 90 - atan(dy / dx) * 180 / 3.14;
	if (dx > 0)
		rotation = angle;
	else
		rotation = angle+180;

	gun.setRotation(rotation);
}

void game::updateevents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
			mousePosition = static_cast<sf::Vector2f>( sf::Mouse::getPosition(*window));
	}
			  
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window->close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				player.move(-1, 0);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
				player.move(1, 0);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
				player.move(0, 1);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
				player.move(0, -1);		
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
	

	updateGun();
}

void game::render()
{
	window->clear();
	window->draw(player);
	window->draw(gun);
	window->display();
}

game::game()
{
	init();

}


game::~game()
{
	delete window;
}

