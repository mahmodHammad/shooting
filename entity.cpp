#include "Entity.h"

void Entity::setRenderWindow(sf::RenderWindow* window)
{
	Window = window;
	mplayer= new Player(window, sf::Vector2f(400, 400), sf::Vector2f(100, 50), sf::Color::Blue,12);
	aplayer = new Player(window, sf::Vector2f(200, 600), sf::Vector2f(60, 60), sf::Color::Magenta,5);
	gplayer = new Player(window, sf::Vector2f(800, 600), sf::Vector2f(20, 160), sf::Color::Red,6);
	fplayer = new Player(window, sf::Vector2f(200, 000), sf::Vector2f(40, 120), sf::Color::White,3);
	restart();
}

void Entity::init()
{
	
}

void Entity::gameover()
{
	players[0]->update();
	for (size_t i = 0; i <projs.size(); i++)
		delete projs[i];
	projs.clear();

}

void Entity::restart()
{	
	players.clear();
	players.push_back(mplayer);
	players.push_back(aplayer);
	players.push_back(fplayer);
	players.push_back(gplayer);	
	reset();
}


void Entity::inputHandler()
{
	keyhandler.updateinput();
	
	if (keyhandler.getkey(esc))
		Window->close();

	 if (keyhandler.getkey(left))
		 if (mplayer->GetPosition().x > 0) {
			 for (size_t i = 0; i < players.size(); i++)
			 players[i]->Move(-1, 0);
			
		}
	 if (keyhandler.getkey(right))
		 if (players[0]->GetPosition().x + players[0]->GetSize().x < Window->getSize().x) {
			 for (size_t i = 0; i < players.size(); i++)
				 players[i]->Move(1, 0);
		}

	 if (keyhandler.getkey(down))
		 if (players[0]->GetPosition().y + players[0]->GetSize().y < Window->getSize().y) {
			 for (size_t i = 0; i < players.size(); i++)
				 players[i]->Move(0, 1);
		 }

	 if (keyhandler.getkey(top))
		 if (players[0]->GetPosition().y > 0)
		 {
			 for (size_t i = 0; i < players.size(); i++)
				 players[i]->Move(0, -1);
		 }
	 if (keyhandler.getkey(rclick))
		 reload = true;
	 if (keyhandler.getkey(lclick))
	 {
		 if (reload)
			 shoot();
		reload = false;
	 }
	 if(keyhandler.getkey(enter)){
		 restart();
	 }
	 keyhandler.initializer();

}

Entity::Entity()
{
	init();
}


void Entity::reset()
{
	for (size_t i= 0; i <projs.size(); i++)
		delete projs[i];
	projs.clear();

	for (size_t i = 0; i < players.size(); i++)
		players[i]->reset();
}


void Entity::shoot()
{
	for (size_t i = 0; i < players.size(); i++) {
		for (size_t j = 0; j < 3; j++) {
			sf::Vector2f hole = players[i]->GetGunHolePosition()[j];
			projs.push_back(new Projectile(this->Window, players[i]->GetDirection(),hole ));		
		}
	}
}

//colition>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Entity::colide(int i ,Player* plyer )
{
	delete projs[i];
	projs.erase(projs.begin() + i);

	plyer->hit();
	
	if (plyer->getHits() > 5) {
		//this line some times causes bug >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		players.erase(std::find(players.begin(),players.end() ,plyer));
	}
}

void Entity::colitionDetection(Player* splayer)
{
	for (size_t i = 0; i < projs.size(); i++)
	{
		if (projs[i]->getBallCenter().x > splayer->GetPosition().x
			&& projs[i]->getBallCenter().x < splayer->GetPosition().x + splayer->GetSize().x
			&& projs[i]->getBallCenter().y >  splayer->GetPosition().y
			&& projs[i]->getBallCenter().y <  splayer->GetPosition().y + splayer->GetSize().y)
		{
			colide(i,splayer);
		}
	}
}


Entity::~Entity()
{
	//for (size_t i = 0; i < players.size(); i++)
	//	delete players[i];
}

void Entity::update()
{
		inputHandler();

	if (players.size() > 1) {
		for (size_t i = 0; i < players.size(); i++) {
			players[i]->update();
			colitionDetection(players[i]);
		}
		for (size_t i = 0; i < projs.size(); i++)
			projs[i]->update();
	}
	else 
		gameover();
}

void Entity::render()
{
	for (size_t i = 0; i < players.size(); i++)
		players[i]->render();

	for (size_t i = 0; i < projs.size(); i++)
	{
		projs[i]->render();
	}
}

