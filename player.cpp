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
	keyhandler.updateinput();
	if (keyhandler.getkey(esc))
	Window->close();
	 if (keyhandler.getkey(left))
		if(mplayer.getPosition().x >0)
			 mplayer.move(-1*speed, 0);
	 if (keyhandler.getkey(right))
		 if (mplayer.getPosition().x +  mplayer.getSize().x < Window->getSize().x)
			mplayer.move(1*speed, 0);
	 if (keyhandler.getkey(down))
		 if (mplayer.getPosition().y + mplayer.getSize().y < Window->getSize().y)
			mplayer.move(0, 1 *speed);
	 if (keyhandler.getkey(top))
		 if (mplayer.getPosition().y >0)
			mplayer.move(0, -1 *speed);
	 
	 if (keyhandler.getkey(rclick))
		 reload = true;
	 if (keyhandler.getkey(lclick))
	 {
		// if (reload)
			 shoot();
		//reload = false;
	 }
	 if(keyhandler.getkey(enter)){
		 reset();
	 }
	 keyhandler.initializer();

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
		hits = 0;
	}
}
void player::reset()
{
	hits = 0;
	for (int i = 0; i <projs.size(); i++)
		delete projs[i];
	projs.clear();

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


void player::setinitpos(sf::Vector2f pos)
{
	initialPostion = pos;
}

void player::setRenderWindow(sf::RenderWindow* window) 
{
	Window = window;
	mplayer.setPosition(initialPostion);

	mygun.setUpGun(window ,0 ,0,playerSize);
	otherGun.setUpGun(window, 0, 1, playerSize);
	otherGun1.setUpGun(window, 0, 2, playerSize);
	otherGun2.setUpGun(window, 2, 0, playerSize);
	otherGun3.setUpGun(window, 2, 1, playerSize);
	otherGun4.setUpGun(window, 2, 2, playerSize);
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

//void player::setup()
//{
////	initialPostion = sf::Vector2f(Window->getSize().x / 2 - mplayer.getSize().x / 2, Window->getSize().y - mplayer.getSize().y - 30);
//}