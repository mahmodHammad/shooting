#include "Player.h"

void Player::setupPlayer(sf::RenderWindow * window, sf::Vector2f initialPosition)
{
	this->window = window;
	mygun.setUpGun(window, 1, 1,playerSize);
	initialPostion = initialPosition;
	reset();
}

void Player::hit()
{
	hits++;
	if (hits == 1)
		this->mplayer.setFillColor(sf::Color(72, 205,22, 252));
	else if (hits == 2)
		this->mplayer.setFillColor(sf::Color(77, 255, 77, 252));

	else if (hits == 3)
		this->mplayer.setFillColor(sf::Color(254, 254, 254, 255));

	else if (hits > 3) {
		reset();
		hits = 0;
	}
}

void Player::reset()
{
	this->mplayer.setFillColor(defaultCOL);
	mplayer.setPosition(initialPostion);
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


void Player::init()
{
	defaultCOL = sf::Color(155, 0, 0, 255);
	playerSize = sf::Vector2f(50, 70);
	speed = 4;
	mplayer.setFillColor(defaultCOL);
	mplayer.setSize(playerSize);
	hits = 0;
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
{
	init();
}

Player::Player(sf::RenderWindow * window, sf::Vector2f inposition,
	sf::Vector2f size, sf::Color Defcolr, float speed)
	:window(window),initialPostion(inposition),playerSize(size),defaultCOL(Defcolr),speed(speed)
{}

Player::~Player()
{}


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

sf::Vector2f Player::GetGunHolePosition()
{
	return GunHolePosition;
}


void Player::update()
{
	mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
	updatevectors();
	updateAngle();
	mygun.update(playerCenter, rotation, this->unitV);
	GunHolePosition =mygun.getGunPos();

}
void Player::render()
{
	window->draw(mplayer);
	mygun.render();
}