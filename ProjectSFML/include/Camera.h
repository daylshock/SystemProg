#pragma once
#include <SFML/Graphics.hpp>
#include "include/Player.h"
class Camera
{
private:
	sf::Vector2f posPlayer;
	sf::View* view;
	sf::Vector2f viewCenter;
public:
	sf::Vector2f diff;
	Camera();
	~Camera();
	void updateCAMERA(Player*& , float);
	sf::View* getView();
};