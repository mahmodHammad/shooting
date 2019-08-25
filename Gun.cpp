#include "Gun.h"


//inttialization ---------------------------------------------------------------------------
void Gun::setUpGun(sf::RenderWindow * window, int positionleft, int positiontop,
	sf::Vector2f playersize, sf::Color col,
	sf::Vector2f size )
{
	this->window = window;
	color = col;
	this->size = size;
	indTop = positiontop;
	indleft = positionleft;
	this->playersize = playersize;
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

void Gun::shiftPos()
{
	shiftposition = position; //intialize & reset
	if (indleft == 0) 
		shiftposition.x -= playersize.x/2;
	else if(indleft==2)
		shiftposition.x += playersize.x / 2;

	if (indTop== 0)
		shiftposition.y -= playersize.y / 2;
	else if (indTop == 2)
		shiftposition.y += playersize.y / 2;
}

Gun::Gun()
{}

//-------------------------------------------------------------------------------------------
//
//Gun::~Gun()
//{
//}



void Gun::update(sf::Vector2f positon, float rotaion, sf::Vector2f unitvect)
{
	this->rotaion = rotaion;

	this->position = positon;//may be deleted
	shiftPos();
	
	this->unitVector = unitvect;
	
	updateGun();
}

void Gun::updateGun()
{
	myGun.setPosition(shiftposition);
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

