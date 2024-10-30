#include "include/Camera.h"
Camera::Camera(sf::RectangleShape &sprite_p) : sprite(sprite_p)
{
	view.reset(sf::Rect<float>(300.f, 300.f, 200.f, 200.f));
	view.setCenter(sprite.getPosition());
	paddingSIZE = 30;
}

void Camera::moveCamera(sf::RenderWindow &window, bool move, float time)
{
	switch (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
	case 1:
		if (move && (unsigned short)sf::Mouse::getPosition(window).x > ((unsigned short)window.getSize().x - paddingSIZE)) { view.move(0.1f * time, 0); }
		if (move && (unsigned short)sf::Mouse::getPosition(window).x < (((unsigned short)window.getSize().x - (unsigned short)window.getSize().x)) + paddingSIZE) { view.move(-0.1f * time, 0); }
		if (move && (unsigned short)sf::Mouse::getPosition(window).y > ((unsigned short)window.getSize().y - paddingSIZE)) { view.move(0, 0.1f * time); }
		if (move && (unsigned short)sf::Mouse::getPosition(window).y < (((unsigned short)window.getSize().y - (unsigned short)window.getSize().y)) + paddingSIZE) { view.move(0, -0.1f * time); }
		break;
	case 0:
		view.setCenter(sprite.getPosition());
		break;
	}
	window.setView(view);
}