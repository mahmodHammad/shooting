#include "player.h"


void player::init()
{
	defaultCOL = sf::Color(155, 0, 0, 255);
	mplayer.setFillColor(defaultCOL);
	mplayer.setSize(sf::Vector2f(30, 40));
	
	//mygun.setUpGun(Window);
	speed = 4;
}



void player::inputHandler()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	Window->close();
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		if(mplayer.getPosition().x >0)
			 mplayer.move(-1*speed, 0);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		 if (mplayer.getPosition().x +  mplayer.getSize().x < Window->getSize().x)
			mplayer.move(1*speed, 0);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		 if (mplayer.getPosition().y + mplayer.getSize().y < Window->getSize().y)
			mplayer.move(0, 1 *speed);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		 if (mplayer.getPosition().y >0)
			mplayer.move(0, -1 *speed);
	 
	 if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		 reload = true;
	 if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	 {
		 if (reload)
			 shoot();
		reload = false;
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
		 reset();
	 }
}


player::player()
{
	init();
}
void player::hit()
{
	
	if (hits == 1)
		this->mplayer.setFillColor(sf::Color(72, 205,22, 252));
	else if (hits == 2)
		this->mplayer.setFillColor(sf::Color(77, 255, 77, 252));

	else if (hits == 3)
		this->mplayer.setFillColor(sf::Color(254, 254, 254, 255));

	else if (hits > 3) {
		reset();
	}
}
void player::reset()
{
	hits = 0;
	projs.clear();
	this->mplayer.setFillColor(defaultCOL);
	mplayer.setPosition(initialPostion);
}
void player::shoot()
{
	projs.push_back(new Projectile(this->Window, unitV, mygun.getGunPos()));

}


void player::setUnitVector()
{
	 dy = playerCenter.y - mousePosition.y;
	 dx = -(playerCenter.x - mousePosition.x);
	unitV = sf::Vector2f(-dx / sqrt((dx*dx) + (dy*dy)), dy / sqrt((dx*dx) + (dy*dy)));
	playerCenter = sf::Vector2f(mplayer.getPosition().x + mplayer.getSize().x / 2, mplayer.getPosition().y + mplayer.getSize().y / 2);

}

void player::updateAngle()
{
	float angle = 90 - atan(dy / dx) * 180 / 3.14;
	if (dx > 0)
		rotation = angle;
	else
		rotation = angle + 180;
}


void player::colide()
{
	for (size_t i = 0; i < projs.size(); i++)
	{
		if  (projs[i]->getBallCenter().x > mplayer.getPosition().x 
		  && projs[i]->getBallCenter().x < mplayer.getPosition().x + mplayer.getSize().x
		  && projs[i]->getBallCenter().y >  mplayer.getPosition().y
		  && projs[i]->getBallCenter().y <  mplayer.getPosition().y + mplayer.getSize().y )
		{ 
			projs.erase(projs.begin()+i);
			hits++;
			hit();
		}
				
	}
}

void player::setRenderWindow(sf::RenderWindow * window)
{
	Window = window;
	mygun.setUpGun(window);
}


player::~player()
{
}

void player::update()
{
	inputHandler();
	mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*Window));
	setUnitVector();

	updateAngle();
	mygun.update(playerCenter, rotation, this->unitV);
	colide();
	 
	//update projs
	for (size_t i = 0; i < projs.size(); i++)
	{
		projs[i]->update();
	}
}

void player::render()
{
	Window->draw(mplayer);
	mygun.render();
	
	for (size_t i = 0; i < projs.size(); i++)
	{
		projs[i]->render();
	}
}

void player::setup()
{
	initialPostion = sf::Vector2f( Window->getSize().x / 2 - mplayer.getSize().x / 2, Window->getSize().y - mplayer.getSize().y -30);
	mplayer.setPosition(initialPostion);
}
