#include "include/AnimForPlayer.h"

animRUN::animRUN(sf::Sprite& sprite) : Animation(sprite)
{
	Animation::addFrame({ sf::IntRect(50,5, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,40, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,75, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,115, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,160, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,195, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,235, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,235, 31, 35), 0.1 });
}
void animRUN::animRUNupdate(float elapsedTime)
{
	Animation::update(elapsedTime);
}

animIDLE::animIDLE(sf::Sprite& sprite) : Animation(sprite)
{
	Animation::addFrame({ sf::IntRect(50,5, 31, 35), 0.2 });
	Animation::addFrame({ sf::IntRect(50,40, 31, 35), 0.2 });
	Animation::addFrame({ sf::IntRect(50,80, 31, 35), 0.2 });
	Animation::addFrame({ sf::IntRect(50,120, 31, 35), 0.2 });
	Animation::addFrame({ sf::IntRect(50,160, 31, 35), 0.2 });
}
void animIDLE::animIDLEupdate(float elapsedTime)
{
	Animation::update(elapsedTime);
}

animATACK::animATACK(sf::Sprite& sprite) : Animation(sprite)
{
	Animation::addFrame({ sf::IntRect(45,5, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,40, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,80, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,120, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,160, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,195, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,235, 80, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(45,275, 80, 35), 0.1 });
}
void animATACK::animATACKupdate(float elapsedTime)
{
	Animation::update(elapsedTime);
}
animCHARGE::animCHARGE(sf::Sprite& sprite) : Animation(sprite) 
{
	Animation::addFrame({ sf::IntRect(50,5, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,45, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,85, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,125, 31, 35), 0.1 });
}
void animCHARGE::animCHARGEupdate(float elapsedTime)
{
	Animation::update(elapsedTime);
}
animHIT::animHIT(sf::Sprite& sprite) : Animation(sprite)
{
	Animation::addFrame({ sf::IntRect(50,5, 31, 35), 0.1 });
	Animation::addFrame({ sf::IntRect(50,45, 31, 35), 0.1 });
}
void animHIT::animHITupdate(float elapsedTime) 
{
	Animation::update(elapsedTime);
}