#include "InputHandler.h"

void InputHandler::initializer()
{
	inputs[left]  = false;
	inputs[right] = false;
	inputs[top]   = false;
	inputs[down]  = false;
	inputs[enter] = false;
	inputs[lclick]= false;
	inputs[rclick]= false;
	inputs[enter] = false;
}

InputHandler::InputHandler()
{
}

void InputHandler::updateinput()
{
	initializer();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		inputs[esc] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		inputs[left] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		inputs[right] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		inputs[down] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		inputs[top] = true;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		inputs[rclick] = true;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		inputs[lclick] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
		inputs[enter] = true;
}

bool InputHandler::getkey(int en)
{
	return inputs[en];
}

