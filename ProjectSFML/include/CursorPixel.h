#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <map>
#include <iostream>
class Cursor 
{
private:
	bool isClick;
	sf::Image* _imageCur;
	sf::Cursor* _cursor;
	/*std::map<sf::Image, const char*> vec;*/
	bool setCursor();
public:
	Cursor();
	~Cursor();
	sf::Cursor* getCursor();
};