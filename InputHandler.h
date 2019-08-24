#pragma once
#include<SFML\Window.hpp>
#include<map>
class InputHandler
{
	enum keys
	{
		top,left,right,down,esc,enter,lclick,rclick
	};
	std::map<int, bool> inputs;
public:
	void initializer();
	void updateinput();
	InputHandler();
	bool getkey(int en);
};

