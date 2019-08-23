#include "Gun.h"


//inttialization ---------------------------------------------------------------------------
void Gun::setUpGun(sf::RenderWindow * window, sf::Color col, sf::Vector2f size, int positionleft, int positiontop)
{
	this->window = window;
	color = col;
	this->size = size;
	indTop = positiontop;
	indleft = positionleft;
	//i may need inital position
	origin = sf::Vector2f(size.x / 2, size.y);
	myGun.setOrigin(origin);
	

	initGun();
}

void Gun::initGun()
{
	myGun.setFillColor(color);
	myGun.setSize(size);
}

Gun::Gun()
{}

//-------------------------------------------------------------------------------------------

Gun::~Gun()
{
}



void Gun::update(sf::Vector2f positon, float rotaion, sf::Vector2f unitvect)
{
	this->rotaion = rotaion;
	this->position = positon;
	this->unitVector = unitvect;
	
	updateGun();
}

void Gun::updateGun()
{
	myGun.setPosition(position);
	myGun.setRotation(rotaion);
}

void Gun::render()
{
	window->draw(myGun);
}

sf::Vector2f Gun::getGunPos()
{
	float height = myGun.getLocalBounds().height;
	sf::Vector2f temp;
	temp.x = myGun.getPosition().x - unitVector.x*myGun.getLocalBounds().height;
	temp.y = myGun.getPosition().y - unitVector.y*myGun.getLocalBounds().height;
	return temp;
}
