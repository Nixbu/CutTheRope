#include "Level.h"

Level::Level() : m_world()
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
