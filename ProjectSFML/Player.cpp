#include "include/Player.h"

Player::Player() : animRUN(player), animIDLE(player), animATACK(player), animCHARGE(player), animHIT(player)
{
	health = 100.0f;
	speed = 104.0f;
	position = player.getPosition();

		playerLEFT = false,
		playerRIGHT = false,
		playerUP = false,
		playerDOWN = false,
		playerATACK = false;
		playerCHARGE = false;
		playerHIT = false;

	timeAtack = 2.4f;
	timeCharge = 2.0f;

	bufferRUN.loadFromFile("Assets/Run/Dirt/DIRT - Run Short 5.wav");
	soundRun.setBuffer(bufferRUN);
	soundRun.setPitch(2.2f);
	soundRun.setVolume(20);

	bufferATACK.loadFromFile("Assets/Attacks/Sword Attacks Hits and Blocks/Sword Attack 1.wav");
	soundAtack.setBuffer(bufferATACK);
	soundAtack.setPitch(1.0f);
	soundAtack.setVolume(30);

	bufferHIT.loadFromFile("Assets/Attacks/Sword Attacks Hits and Blocks/Sword Impact Hit 2.wav");
	soundHit.setBuffer(bufferHIT);

	textureRUN.loadFromFile("Ball and Chain Bot/run.png");
	textureIDLE.loadFromFile("Ball and Chain Bot/idle.png");
	textureATACK.loadFromFile("Ball and Chain Bot/attack.png");
	textureCHARGE.loadFromFile("Ball and Chain Bot/charge.png");
	textureHIT.loadFromFile("Ball and Chain Bot/hit.png");

	player.setOrigin(17.5, 15.5);
	position = sf::Vector2f(20, 20);
}
sf::Sprite Player::getSprite() { return player; }

float Player::getTIMEATACK() 
{
	return timeAtack;
}
float Player::getTIMECHARGE() 
{
	return timeCharge;
}
float Player::getHEALTH() 
{ return health; }
sf::Vector2f Player::getPostion() 
{
	return position;
}

void Player::soundPLAYER(const char* sym) 
{
	if (sym = "HIT") 
	{
		if (Player::isHIT() && soundHit.getStatus() != sf::Music::Playing)
		{
			soundHit.play();
		}
		else if (!Player::isHIT() && soundHit.getStatus()) { soundHit.stop(); }
	}
	if (sym = "ATACK") 
	{
		if (Player::isATACK() && soundAtack.getStatus() != sf::Music::Playing)
		{
			soundAtack.play();
		}
		else if (!Player::isATACK() && soundAtack.getStatus()) { soundAtack.stop(); }
	}
	if (sym = "RUN") 
	{
		if (Player::isRUN() && soundRun.getStatus() != sf::Music::Playing)
		{
			soundRun.play();
		}
		else if (!Player::isRUN() && soundRun.getStatus()) { soundRun.stop(); }
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
//void Player::playerKMOUSELEFT_R() { playerATACK = false; }

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

void Player::update(float elapsedTime) 
{
	if (Player::isRUN()) { player.setTexture(textureRUN, 1); animRUN::animRUNupdate(elapsedTime);}
	if (!Player::isRUN()) { player.setTexture(textureIDLE, 1); animIDLE::animIDLEupdate(elapsedTime);}
	if (Player::isRUN() && playerLEFT) Player::playerMirrored();
	if (Player::isRUN() && playerRIGHT) Player::playerNOTMirrored();
	if (Player::isATACK() && (int)timeAtack != 0.0f)
	{
		playerLEFT = false;
		playerRIGHT = false;
		playerUP = false;
		playerDOWN = false;

		timeAtack -= (1.0f * (elapsedTime));
		player.setTexture(textureATACK, 1); animATACK::animATACKupdate(elapsedTime);
	}
	else {playerATACK = false; timeAtack = 2.4f;}
	if (Player::isCHARGE() && (int)timeCharge != 0.0f && Player::isRUN()) 
	{
		playerATACK = false;
		speed = 150.0f;
		timeCharge -= (1.0f * (elapsedTime));
		player.setTexture(textureCHARGE, 1);
		animCHARGE::animCHARGEupdate(elapsedTime);
	}
	else { playerCHARGE = false; timeCharge = 2.0f; speed = 104.0f; }
	if (Player::isHIT() && (int)health != 0) {
		playerATACK = false;
		playerCHARGE = false;

		playerDOWN = false;
		playerUP = false;
		playerLEFT = false;
		playerRIGHT = false;

		health -= (24.0f * elapsedTime);
		player.setTexture(textureHIT, 1);
		animHIT::animHITupdate(elapsedTime);
	}
	else playerHIT = false;
	Player::playerControl(elapsedTime);
	player.setPosition(position);
}

