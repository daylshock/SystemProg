#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include "DebugInterface.h"
#include "Camera.h"
class Engine 
{
private:
	sf::RenderWindow window;
	Player player;
	Camera cam;
	sf::View view;
	DebugInteface deb;
	void input();
	void update(float dtAsSeconds);
	void render();
public:
	Engine();
	void start();
};