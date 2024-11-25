#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <mutex>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include "DebugInterface.h"
#include "Camera.h"
#include "CursorPixel.h"
class Engine
{
private:
	sf::RenderWindow* window;
	Player* _ptrplayer;
	DebugInteface* _ptrdeb;
	Camera* _ptrcameraPlayer;
	Cursor* _ptrcursor;
	void input();
	void update(float);
	void render();
	inline void _renderPlayer();
	inline void _renderDebugInfo();
	inline void handleKeyPressed(sf::Keyboard::Key);
	inline void handleKeyReleased(sf::Keyboard::Key);
	inline void toggleDebug();
public:
	Engine();
	~Engine();
	void start();
};