#pragma once
#include<SFML\Window.hpp>
#include<map>
class InputHandler
{
	std::map<int, bool> inputs;
public:
	enum keys
	{
		top,left,right,down,esc,enter,lclick,rclick
	};
	void initializer();
	void updateinput();
	InputHandler();
	bool getkey(int en);
};

