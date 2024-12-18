#pragma once
#include <SFML/Graphics.hpp>
#include "include/Player.h"
#include "include/Camera.h"
#include <sstream>

class DebugInteface
{
private:
	sf::Font font;
	sf::Text text;
	bool DebugActive;
public:
	DebugInteface();
	void degubACTIVE();
	void degubDISABLE();
	bool isDebug();
	sf::Text getTextDebug();
	void updateDEBUG(sf::RenderWindow*& , Camera*&, Player*& , float );
};