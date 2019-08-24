#include "Entity.h"

void Entity::setRenderWindow(sf::RenderWindow* window)
{
	Window = window;
	mplayer.setupPlayer(window, sf::Vector2f(222, 444));
	aplayer.setupPlayer(window, sf::Vector2f(622, 444));
	//mplayer= new Player(window, sf::Vector2f(400, 400), sf::Vector2f(100, 50), sf::Color::Blue);
//	aplayer= new Player(window, sf::Vector2f(200, 600), sf::Vector2f(60, 60), sf::Color::Magenta);
}

void Entity::init()
{
	//mplayer.setupPlayer(this->Window, sf::Vector2f(100, 200));
}

void Entity::inputHandler()
{
	keyhandler.updateinput();
	if (keyhandler.getkey(esc))
	Window->close();

	 if (keyhandler.getkey(left))
		 if (mplayer.GetPosition().x > 0) {
			 mplayer.Move(-1, 0);
			 aplayer.Move(-1, 0);

		}
	 if (keyhandler.getkey(right))
		 if (mplayer.GetPosition().x + mplayer.GetSize().x < Window->getSize().x) {
			mplayer.Move(1, 0);
			aplayer.Move(1, 0);
		 }
	 if (keyhandler.getkey(down))
		 if (mplayer.GetPosition().y + mplayer.GetSize().y < Window->getSize().y)
			mplayer.Move(0, 1 );
	 if (keyhandler.getkey(top))
		 if (mplayer.GetPosition().y >0)
			mplayer.Move(0, -1 );
	 
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

Entity::Entity()
{
	init();
}


void Entity::reset()
{
	for (int i = 0; i <projs.size(); i++)
		delete projs[i];
	projs.clear();

	mplayer.reset();
	aplayer.reset();
}


void Entity::shoot()
{
	projs.push_back(new Projectile(this->Window, mplayer.GetDirection(), mplayer.GetGunHolePosition()));
	projs.push_back(new Projectile(this->Window, aplayer.GetDirection(), aplayer.GetGunHolePosition()));
}

//colition>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Entity::colide(int i)
{
	delete projs[i];
	projs.erase(projs.begin() + i);
	
	mplayer.hit();
	aplayer.hit();
}

void Entity::colitionDetection(Player splayer)
{
	for (size_t i = 0; i < projs.size(); i++)
	{
		if (projs[i]->getBallCenter().x > splayer.GetPosition().x
			&& projs[i]->getBallCenter().x < splayer.GetPosition().x + splayer.GetSize().x
			&& projs[i]->getBallCenter().y >  splayer.GetPosition().y
			&& projs[i]->getBallCenter().y <  splayer.GetPosition().y + splayer.GetSize().y)
		{
			colide(i );
			splayer.hit();
		}
	}
}


Entity::~Entity()
{
}

void Entity::update()
{
	mplayer.update();
	aplayer.update();
	inputHandler();
	colitionDetection(mplayer);
	colitionDetection(aplayer);
	for (size_t i = 0; i < projs.size(); i++)
		projs[i]->update();
}

void Entity::render()
{
	mplayer.render();
	aplayer.render();
	for (size_t i = 0; i < projs.size(); i++)
	{
		projs[i]->render();
	}
}

