#include "include/Camera.h"
Camera::Camera() : view(new sf::View(sf::FloatRect(0, 0, 640, 360)))
{
	std::cout << "_ptrcameraPlayer CREATE\n";
}
Camera::~Camera() 
{
	if (view != nullptr) 
	{ 
		delete			view;
						view = nullptr; 
						std::cout << "view DEL \n";
	}
}
void Camera::updateCAMERA(Player*& player, float elapsed)
{
	viewCenter = view->getCenter();
	posPlayer = player->getPostion();
	diff = posPlayer - viewCenter;
	view->move(diff * elapsed);
}
sf::View* Camera::getView() { return view; }