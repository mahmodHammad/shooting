#include "Player.h"

Player::Player(sf::RenderWindow * window, sf::Vector2f inposition,
	sf::Vector2f size, sf::Color Defcolr, float speed)
	:Window(window), initialPostion(inposition), playerSize(size), defaultCOL(Defcolr), speed(speed)
{
	mygun.setUpGun(Window, 1, 2, playerSize);
	aygun.setUpGun(Window, 1, 0, playerSize);
	sygun.setUpGun(Window, 1, 1,playerSize);
	guns.push_back(mygun);
	guns.push_back(aygun);
	guns.push_back(sygun);
		reset();
		
}

void Player::hit()
{
	hits++;
	if (hits == 1)
		this->mplayer.setFillColor(sf::Color(72, 205,22, 252));
	else if (hits == 2)
		this->mplayer.setFillColor(sf::Color(77, 255, 222, 252));

	else if (hits == 3)
		this->mplayer.setFillColor(sf::Color(125, 254, 154, 255));
	else if (hits == 4)
		this->mplayer.setFillColor(sf::Color(254, 254, 25, 255));
	else if (hits == 5)
		this->mplayer.setFillColor(sf::Color(254, 25, 254, 255));

	else if (hits >9) {
		reset();
		hits = 0;
	}
}

void Player::reset()
{
	this->mplayer.setFillColor(defaultCOL);
	mplayer.setPosition(initialPostion);
	mplayer.setSize(playerSize);
	hits = 0;

}

void Player::Move(int x, int y)
{
	mplayer.move(x*speed, y*speed);
}


void Player::updatevectors()
{
	dy = playerCenter.y - mousePosition.y;
	dx = -(playerCenter.x - mousePosition.x);
	unitV = sf::Vector2f(-dx / sqrt((dx*dx) + (dy*dy)), dy / sqrt((dx*dx) + (dy*dy)));
	playerCenter = sf::Vector2f(mplayer.getPosition().x + mplayer.getSize().x / 2, mplayer.getPosition().y + mplayer.getSize().y / 2);
}


void Player::updateAngle()
{
	float angle = 90 - atan(dy / dx) * 180 / 3.14;
	if (dx > 0)
		rotation = angle;
	else
		rotation = angle + 180;
}

Player::Player()
{}

//Player::~Player()
//{}

int Player::getHits()
{
	return hits;
}


sf::Vector2f Player::GetPosition()
{
	return mplayer.getPosition();
}

sf::Vector2f Player::GetSize()
{
	return mplayer.getSize();
}

sf::Vector2f Player::GetDirection()
{
	return unitV;
}

std::vector<sf::Vector2f> Player::GetGunHolePosition()
{
	return gunposs;
}

void Player::update()
{
	mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*Window));
	updatevectors();
	updateAngle();
		gunposs.clear();
	for (size_t i = 0; i < guns.size(); i++) {
		guns[i].update(playerCenter, rotation, this->unitV);
		gunposs .push_back(guns[i].getGunPos());//what the hell
	}

}

void Player::render()
{
	Window->draw(mplayer);
	for (size_t i = 0; i < guns.size(); i++)
		guns[i].render();
}