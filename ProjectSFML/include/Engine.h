#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include "DebugInterface.h"

class Engine 
{
private:
	sf::RenderWindow window;
	Player player; 
	sf::View view;
	DebugInteface deb;
	float getFPS(float dtAsSeconds);
	void input();
	void render();
	void update(float dtAsSeconds);
public:
	Engine();
	void start();
};