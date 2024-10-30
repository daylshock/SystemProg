#pragma once
#include "Animation.h"

class animRUN : public Animation
{
public:
	animRUN(sf::Sprite& sprite);
	void animRUNupdate(float elapsedTime);
};

class animIDLE : public Animation
{
public:
	animIDLE(sf::Sprite& sprite);
	void animIDLEupdate(float elapsedTime);
};

class animATACK : public Animation 
{
public:
	animATACK(sf::Sprite& sprite);
	void animATACKupdate(float elapsedTime);
};

class animCHARGE : public Animation 
{
public:
	animCHARGE(sf::Sprite& sprite);
	void animCHARGEupdate(float elapsedTime);
};

class animHIT : public Animation 
{
public:
	animHIT(sf::Sprite& sprite);
	void animHITupdate(float elapsedTime);
};