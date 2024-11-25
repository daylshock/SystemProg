#include "include/DebugInterface.h"

DebugInteface::DebugInteface()
{
	std::cout << "_ptrdeb CREATE\n";
	DebugActive = false;
	font.loadFromFile("Monocraft.otf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(15);
	text.setPosition(0, 0);
}
sf::Text DebugInteface::getTextDebug() 
{
	return text;
}
bool DebugInteface::isDebug() 
{ 
	if (DebugActive) return true;
	else return false;
}

void DebugInteface::degubACTIVE(){DebugActive = true;}
void DebugInteface::degubDISABLE(){DebugActive = false;}

void DebugInteface::updateDEBUG(sf::RenderWindow*& window, Camera*& playerCamera, Player*& player, float elapsedTime)
{
	if (DebugInteface::isDebug()) 
	{
		float lastTime = 0;
		float fps = 1.f / (elapsedTime - lastTime);
		lastTime = elapsedTime;

		text.setFillColor(sf::Color::Yellow);
		std::stringstream ss;
		ss << "DebugACTIVE: \n"
			<< "LastTime: (" << lastTime << ")\n"
			<< "FPS: (" << fps << ")\n"
			<< "Pos x,y: (" << player->getPostion().x << " " << player->getPostion().y << ")\n"
			<< "PosCam x,y: (" << playerCamera->getView()->getCenter().x  << " " << playerCamera->getView()->getCenter().y << ")\n"
			<< "diff cam: (" << playerCamera->diff.x << " " << playerCamera->diff.y << ")\n"
			<< "TimeAttack(LBM): (" << std::to_string(player->getTIMEATACK()) << ")\n" 
			<< "TimeCharge(SHIFT): (" << std::to_string(player->getTIMECHARGE()) << ")\n"
			<< "TimeAfterCharge(SHIFT): (" << std::to_string(player->getTIMEAFTECHARGE()) << ")\n"
			<< "HealthPLAYER(PRESS H): (" << std::to_string(player->getHEALTH()) << ")\n"
			<< "Status(RUN(/IDLE), ATACK, CHARGE, HIT): (" << player->isRUN() << " " 
			 << player->isATACK() << " " << player->isCHARGE()  << " " << player->isHIT() << ")"
			<< std::endl;
		text.setString(ss.str());
	}
	else 
	{
		text.setFillColor(sf::Color::White);
		text.setString("DebugDISABLE(TAB)");
	}
}
