#include "include/Player.h"

Player::Player() :	animRUN(player),
					animIDLE(player),
					animATACK(player),
					animCHARGE(player),
					animHIT(player)
{
	std::cout << "player CREATE\n";
	health = 100;
	speed = 104.0f;
	position = player.getPosition();

		playerLEFT = false;
		playerRIGHT = false;
		playerUP = false;
		playerDOWN = false;

		playerATACK = false;
		playerCHARGE = false;
		playerHIT = false;

	timeAtack = 2.4f;
	timeCharge = 2.0f;
	timeAfterCharge = 0.0f;
	player.setOrigin(17.5, 15.5);
	position = sf::Vector2f(20, 20);
		Player::loadRes();
}

void Player::loadRes()
{
	Player::loadTexture("t_IDLE", "Ball and Chain Bot/idle.png");
	Player::loadTexture("t_RUN", "Ball and Chain Bot/run.png");
	Player::loadTexture("t_ATACK", "Ball and Chain Bot/attack.png");
	Player::loadTexture("t_CHARGE", "Ball and Chain Bot/charge.png");
	Player::loadTexture("t_HIT", "Ball and Chain Bot/hit.png");

	if (!bufferRUN->loadFromFile("Assets/Run/Dirt/DIRT - Run Short 5.wav")) {
		std::cerr << "Ошибка при загрузке звука Run\n";
	}
	else {
		soundRun->setBuffer(*bufferRUN);
		soundRun->setPitch(2.2f);
		soundRun->setVolume(20);
	}

	if (!bufferATACK->loadFromFile("Assets/Attacks/Sword Attacks Hits and Blocks/Sword Attack 1.wav")) {
		std::cerr << "Ошибка при загрузке звука Attack\n";
	}
	else {
		soundAtack->setBuffer(*bufferATACK);
		soundAtack->setPitch(1.0f);
		soundAtack->setVolume(30);
	}

	if (!bufferHIT->loadFromFile("Assets/Attacks/Sword Attacks Hits and Blocks/Sword Impact Hit 2.wav")) {
		std::cerr << "Ошибка при загрузке звука Hit\n";
	}
	else {
		soundHit->setBuffer(*bufferHIT);
	}

	// Загрузка текстур
	/*if (!textureRUN.loadFromFile("Ball and Chain Bot/run.png")) {
		std::cerr << "Ошибка при загрузке текстуры Run\n";
	}*/
}
void Player::loadTexture(const char* key, const char* _path) 
{
	sf::Texture* _texture = new sf::Texture;
	
	if (!_texture->loadFromFile(_path)) 
	{ 
		delete			_texture;
						_textures[key] = nullptr;

						std::cerr << "ERROR LOAD FILE TEXTURE -" << *_path << "\n";
						return;
	}
	else _textures[key] = _texture;
}
void Player::loadSound(const char* key, const char* _path) 
{
	sf::SoundBuffer* _tmpsoundbuffer = new sf::SoundBuffer;

	if (!_tmpsoundbuffer->loadFromFile(_path))
	{
		delete			_tmpsoundbuffer;
						std::cerr << "ERROR LOAD SOUNDBUFF -" << _path << "\n";
						std::cerr << "ERROR LOAD SOUND -" << _path << "\n";
	}
	else 
	{
		_soundBuff_s[key] = _tmpsoundbuffer;
		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(*_tmpsoundbuffer);
		_sounds[key] = sound;
	}

}

sf::Sprite Player::getSprite() { return player; }
Player::~Player() 
{
	for (auto& t_pair : _textures) 
	{
		std::cerr << "DEL: " << &(t_pair.second) << "\n";
		delete t_pair.second;
	}
	for (auto& sb_pair : _soundBuff_s) 
	{
		std::cerr << "DEL: " << &(sb_pair.second) << "\n";
		delete sb_pair.second; 
	}
	for (auto& s_pair : _sounds) 
	{
		std::cerr << "DEL: " << &(s_pair.second) << "\n";
		delete s_pair.second; 
	}

	_textures.clear();
	_soundBuff_s.clear();
	_sounds.clear();

	if (bufferRUN != nullptr && bufferATACK != nullptr && bufferHIT != nullptr)
	{
		delete				bufferRUN;
		delete				bufferATACK;
		delete				bufferHIT;

							bufferRUN =	nullptr;
							bufferATACK = nullptr;
							bufferHIT = nullptr;
							std::cout << "buffer DEL\n";
	}
	if (soundRun != nullptr && soundAtack != nullptr && soundHit != nullptr)
	{

		delete				soundRun;
		delete				soundAtack;
		delete				soundHit;

							soundRun = nullptr;
							soundAtack = nullptr;
							soundHit = nullptr;
							std::cout << "sound DEL" << std::endl;
	}
}
float Player::getTIMEATACK() 
{
	return timeAtack;
}
float Player::getTIMECHARGE() 
{
	return timeCharge;
}
int Player::getHEALTH() 
{ return health; }
float Player::getTIMEAFTECHARGE() {
	return timeAfterCharge;
}
sf::Vector2f Player::getPostion() 
{
	return position;
}

void Player::soundPLAYER(const char* typeAnim) 
{
	if (typeAnim = "HIT")
	{
		if (Player::isHIT() && soundHit->getStatus() != sf::Music::Playing)
		{
			soundHit->play();
		}
		else if (!Player::isHIT() && soundHit->getStatus()) { soundHit->stop(); }
	}
	if (typeAnim = "ATACK")
	{
		if (Player::isATACK() && soundAtack->getStatus() != sf::Music::Playing)
		{
			soundAtack->play();
		}
		else if (!Player::isATACK() && soundAtack->getStatus()) { soundAtack->stop(); }
	}
	if (typeAnim = "RUN")
	{
		if (Player::isRUN() && soundRun->getStatus() != sf::Music::Playing)
		{
			soundRun->play();
		}
		else if (!Player::isRUN() && soundRun->getStatus()) { soundRun->stop(); }
	}
}
void Player::soundPLAYERALL() 
{
	Player::soundPLAYER("ATACK");
	Player::soundPLAYER("RUN");
	Player::soundPLAYER("HIT");
}

void Player::playerKLP() { playerLEFT = true; }
void Player::playerKRP() { playerRIGHT = true; }
void Player::playerKUP() { playerUP = true; }
void Player::playerKDP() { playerDOWN = true; }

void Player::playerKLR() { playerLEFT = false; }
void Player::playerKRR() { playerRIGHT = false; }
void Player::playerKUR() { playerUP = false; }
void Player::playerKDR() { playerDOWN = false; }

void Player::playerKKP() { playerHIT = true; }
void Player::playerKKR() { playerHIT = false; }
void Player::playerKSHIFTP() { playerCHARGE = true; }
void Player::playerKMOUSELEFT_P() { playerATACK = true; }

void Player::playerMirrored() 
{
	player.setScale(-1.f, player.getScale().y);
}
void Player::playerNOTMirrored()
{
	player.setScale(1.f, player.getScale().y);
}

bool Player::isRUN()
{
	if (playerLEFT && playerRIGHT && playerUP && playerDOWN) return false;
	if (playerLEFT || playerRIGHT || playerUP || playerDOWN) return true;
	else return false;
}
bool Player::isATACK()
{
	if (playerATACK) return true;
	else return false;
}
bool Player::isCHARGE() 
{
	if (playerCHARGE) return true;
	else return false;
}
bool Player::isHIT() 
{ 
	if (playerHIT) return true;
	else return false;
}

void Player::playerControl(float elapsedTime)
{
	if (playerLEFT) position.x -= speed * elapsedTime;
	if (playerRIGHT) position.x += speed * elapsedTime;
	if (playerUP) position.y -= speed * elapsedTime;
	if (playerDOWN) position.y += speed * elapsedTime;
};

void Player::updatePLAYER(float elapsedTime) 
{
	if (Player::isRUN()) { player.setTexture(*(_textures["t_RUN"]), 1); animRUN::animRUNupdate(elapsedTime); }
	if (!Player::isRUN()) { player.setTexture(*(_textures["t_IDLE"]), 1); animIDLE::animIDLEupdate(elapsedTime);}
	if (Player::isRUN() && playerLEFT) Player::playerMirrored();
	if (Player::isRUN() && playerRIGHT) Player::playerNOTMirrored();
	if (Player::isATACK() && (int)timeAtack != 0.0f)
	{
		playerLEFT = false;
		playerRIGHT = false;
		playerUP = false;
		playerDOWN = false;

		timeAtack -= (1.0f * (elapsedTime));
		player.setTexture(*(_textures["t_ATACK"]), 1); animATACK::animATACKupdate(elapsedTime);
	}
	else {playerATACK = false; timeAtack = 2.4f;}
	if (Player::isCHARGE() && (int)timeCharge != 0.0f && (int)timeAfterCharge == 0.0f && Player::isRUN())
	{
		playerATACK = false;
		speed = 150.0f;
		timeCharge -= (1.0f * elapsedTime);
		player.setTexture(*(_textures["t_CHARGE"]), 1);
		animCHARGE::animCHARGEupdate(elapsedTime);
	}
	else { if ((int)timeCharge == 0.0f) { timeAfterCharge = 10.0f; } playerCHARGE = false; timeCharge = 2.0f; speed = 104.0f; if ((int)timeAfterCharge != 0.0f) { timeAfterCharge -= (1.0f * (elapsedTime)); } }
	if (Player::isHIT() && health != 0) {
		playerATACK = false;
		playerCHARGE = false;

		playerDOWN = false;
		playerUP = false;
		playerLEFT = false;
		playerRIGHT = false;

		health -= (24.0f * elapsedTime);
		player.setTexture(*(_textures["t_HIT"]), 1);
		animHIT::animHITupdate(elapsedTime);
	}
	else playerHIT = false;

	Player::playerControl(elapsedTime);
	player.setPosition(position);
}

