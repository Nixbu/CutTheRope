#include "Level.h"

Level::Level()
{
}

void Level::loadLevel(std::string levelFileName)
{
	// TODO add try catch
	m_levelFile.open(levelFileName);

	this->readLevel();


}

void Level::readLevel()
{
}
