#include "include/DebugInterface.h"

DebugInteface::DebugInteface()
{
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

void DebugInteface::updateDEBUG(Player& player, float elapsedTime)
{
	if (DebugInteface::isDebug()) 
	{
		float lastTime = 0;
		float fps = 1.f / (elapsedTime - lastTime);
		lastTime = elapsedTime;

		text.setFillColor(sf::Color::Yellow);
		std::stringstream ss;
		 ss << "DebugACTIVE: \n" 
			<< "FPS: ("<< fps << ")\n"
			<< "TimeAttack(LBM): (" << std::to_string(player.getTIMEATACK()) << ")\n" 
			<< "TimeCharge(SHIFT): (" << std::to_string(player.getTIMECHARGE()) << ")\n"
			<< "HealthPLAYER(PRESS H): (" << std::to_string(player.getHEALTH()) << ")\n"
			<< "Status(RUN(/IDLE), ATACK, CHARGE, HIT): (" << player.isRUN() << " " 
			 << player.isATACK() << " " << player.isCHARGE()  << " " << player.isHIT() << ")"
			<< std::endl;
		text.setString(ss.str());
	}
	else 
	{
		text.setFillColor(sf::Color::White);
		text.setString("DebugDISABLE(TAB)");
	}
}
