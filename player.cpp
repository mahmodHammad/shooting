#include "player.h"

void player::init()
{
	mplayer.setFillColor(sf::Color::Red);
	mplayer.setSize(sf::Vector2f(150, 50));
}

void player::updateGun()
{
	playerCenter = sf::Vector2f(mplayer.getPosition().x + mplayer.getSize().x / 2, mplayer.getPosition().y + mplayer.getSize().y / 2);
	gun.setPosition(playerCenter);
	float dy = playerCenter.y - mousePosition.y;
	float dx = -(playerCenter.x - mousePosition.x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	unitV = sf::Vector2f(-dx/sqrt((dx*dx)+(dy*dy)), dy / sqrt((dx*dx) + (dy*dy))) ;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	float angle = 90 - atan(dy / dx) * 180 / 3.14;
	if (dx > 0)
		rotation = angle;
	else
		rotation = angle + 180;

	gun.setRotation(rotation);
}

void player::inputHandler()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	Window->close();
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	mplayer.move(-1, 0);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	mplayer.move(1, 0);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	mplayer.move(0, 1);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	mplayer.move(0, -1);

	 if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	 {
		 fire = true;
		 projs.push_back(new Projectile(this->Window ,unitV));
	 }
}

sf::Vector2f player::getGunPos()
{
	float height = gun.getLocalBounds().height;
	sf::Vector2f temp;
	temp.x = gun.getPosition().x - unitV.x*gun.getLocalBounds().height;
	temp.y = gun.getPosition().y -unitV.y*gun.getLocalBounds().height;
	return temp;
}





player::player()
{
	init();
}

void player::setRenderWindow(sf::RenderWindow * window)
{
	Window = window;
}


player::~player()
{
}

void player::update()
{
	inputHandler();
	mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*Window));
	updateGun();
	//update projs
	for (size_t i = 0; i < projs.size(); i++)
	{
		projs[i]->update();
	}
}

void player::render()
{
	Window->draw(mplayer);
	Window->draw(gun);
	//update projs
	for (size_t i = 0; i < projs.size(); i++)
	{
		projs[i]->update();
	}
}

void player::setup()
{
	mplayer.setPosition(Window->getSize().x / 2 - mplayer.getSize().x / 2, Window->getSize().y - mplayer.getSize().y);
	gun.setFillColor(sf::Color::Yellow);
	gun.setSize(sf::Vector2f(5, 70));
	gun.setOrigin(gun.getSize().x / 2, gun.getSize().y);

}
