#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "include/Animation.h"
#include "include/AnimForPlayer.h"
#include <string>
#include <unordered_map>

class Player : public animRUN, public animIDLE, public animATACK, public animCHARGE, public animHIT
{
private:
	sf::Sprite player;

	std::unordered_map<const char*, sf::Texture*> _textures;
	std::unordered_map<const char*, sf::SoundBuffer*> _soundBuff_s;
	std::unordered_map<const char*, sf::Sound*> _sounds;

		void loadRes();
		void loadTexture(const char*, const char*);
		void loadSound(const char*, const char*);

	float timeAtack;
	float timeCharge;
	float timeAfterCharge;

	int health;

	float speed;
	sf::Vector2f position;
	bool playerLEFT, playerRIGHT, playerUP, playerDOWN;
	bool playerATACK, playerCHARGE;
	bool playerHIT;

	sf::SoundBuffer* bufferRUN = new sf::SoundBuffer;
	sf::SoundBuffer* bufferATACK = new sf::SoundBuffer;
	sf::SoundBuffer* bufferHIT = new sf::SoundBuffer;

	sf::Sound* soundRun = new sf::Sound;
	sf::Sound* soundAtack = new sf::Sound;
	sf::Sound* soundHit = new sf::Sound;

	void playerControl(float);
	void soundPLAYER(const char*);

public:
	void soundPLAYERALL();

	float getTIMEATACK();
	float getTIMECHARGE();
	int getHEALTH();
	float getTIMEAFTECHARGE();
	sf::Vector2f getPostion();

	bool isRUN();
	bool isATACK();
	bool isCHARGE();
	bool isHIT();

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
	~Player();
	sf::Sprite getSprite();
	void updatePLAYER(float elapsedTime);
};