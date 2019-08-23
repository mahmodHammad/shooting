#include "player.h"


void player::init()
{
	defaultCOL = sf::Color(155, 0, 0, 255);
	playerSize = sf::Vector2f(50, 70);
	speed = 4;

	mplayer.setFillColor(defaultCOL);
	mplayer.setSize(playerSize);
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
	for (int i = 0; i <projs.size(); i++)
		delete projs[i];

	this->mplayer.setFillColor(defaultCOL);
	mplayer.setPosition(initialPostion);
}
void player::shoot()
{

	projs.push_back(new Projectile(this->Window, unitV, mygun.getGunPos()));

	projs.push_back(new Projectile(this->Window, unitV, otherGun.getGunPos()));
	projs.push_back(new Projectile(this->Window, unitV, otherGun1.getGunPos()));
	projs.push_back(new Projectile(this->Window, unitV, otherGun2.getGunPos()));
	projs.push_back(new Projectile(this->Window, unitV, otherGun3.getGunPos()));
	projs.push_back(new Projectile(this->Window, unitV, otherGun4.getGunPos()));


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
			delete projs[i];
			projs.erase(projs.begin()+i);
			hits++;
			hit();
		}
				
	}
}

void player::setRenderWindow(sf::RenderWindow* window) 
{
	Window = window;
	//<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><>
	mygun.setUpGun(window ,0 ,0,playerSize);
	otherGun.setUpGun(window, 0, 1, playerSize);
	otherGun1.setUpGun(window, 0, 2, playerSize);
	otherGun2.setUpGun(window, 1, 1, playerSize);
	otherGun3.setUpGun(window, 1, 2, playerSize);
	otherGun4.setUpGun(window, 1, 0, playerSize);

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
	otherGun.update(playerCenter, rotation, this->unitV);
	otherGun1.update(playerCenter, rotation, this->unitV);
	otherGun2.update(playerCenter, rotation, this->unitV);
	otherGun3.update(playerCenter, rotation, this->unitV);
	otherGun4.update(playerCenter, rotation, this->unitV);

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
	otherGun.render();
	otherGun1.render();
	otherGun2.render();
	otherGun3.render();
	otherGun4.render();

	
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
