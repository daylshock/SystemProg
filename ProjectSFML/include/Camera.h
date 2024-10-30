#pragma once
#include<SFML/Graphics.hpp>

class Camera
{
public:
	Camera(sf::RectangleShape &sprite_p);
	void moveCamera(sf::RenderWindow &window, bool move, float time);
private:
	unsigned short paddingSIZE;
	sf::View view;
	sf::RectangleShape sprite;
};
