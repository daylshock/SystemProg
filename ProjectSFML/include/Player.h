#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "include/Animation.h"
#include "include/AnimForPlayer.h"
#include <string>

class Player : public animRUN, public animIDLE, public animATACK, public animCHARGE, public animHIT
{
private:
	sf::Sprite player;
	sf::Texture textureRUN;
	sf::Texture textureIDLE;
	sf::Texture textureATACK;
	sf::Texture textureCHARGE;
	sf::Texture textureHIT;

	float timeAtack;
	float timeCharge;
	float health;
	float speed;
	sf::Vector2f position;
	bool playerLEFT, playerRIGHT, playerUP, playerDOWN;
	bool playerATACK, playerCHARGE;
	bool playerHIT;

	sf::SoundBuffer bufferRUN;
	sf::SoundBuffer bufferATACK;
	sf::SoundBuffer bufferHIT;

	sf::Sound soundRun;
	sf::Sound soundAtack;
	sf::Sound soundHit;
	void playerControl(float elapsedTime);
	void soundPLAYER(const char* );
public:
	void soundPLAYERALL();

	float getTIMEATACK();
	float getTIMECHARGE();
	float getHEALTH();
	bool isRUN();
	bool isATACK();
	bool isCHARGE();
	bool isHIT();
	/*void playSoundRUN();
	void stopSoundRUN();*/
	void playerKMOUSELEFT_P();
	void playerKSHIFTP();
	void playerKKP();
	void playerKKR();
	void playerKLP();
	void playerKRP();
	void playerKUP();
	void playerKDP();

	
	void playerKLR();
	void playerKRR();
	void playerKUR();
	void playerKDR();

	void playerMirrored();
	void playerNOTMirrored();
	
	Player();
	sf::Sprite getSprite();
	void update(float elapsedTime);

};