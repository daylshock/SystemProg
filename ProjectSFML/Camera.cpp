#include "include/Camera.h"
void Camera::updateCamera(sf::RenderWindow& window, sf::View& view, Player& sprite, float elapsed)
{
	view.reset(sf::Rect<float>(0.0f, 0.0f, 640, 360));
	view.setCenter(sprite.getPostion());
}