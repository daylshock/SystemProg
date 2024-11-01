#pragma once
#include<SFML/Graphics.hpp>
#include "include/Player.h"
class Camera
{
public:
	void updateCamera(sf::RenderWindow& window, sf::View& view, Player& sprite, float elapsed);
};
