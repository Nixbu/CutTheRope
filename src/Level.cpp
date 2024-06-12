#include "Level.h"

Level::Level() : m_world()
{
}

void Level::loadLevel(std::string levelFileName)
{
	// TODO add try catch
	m_levelFile.open(levelFileName);

	this->readLevel();

	m_levelFile.close();


}

void Level::draw(sf::RenderWindow& window) const
{
	this->m_world.draw(window);
}

void Level::readLevel()
{
	std::string line;

	while (std::getline(this->m_levelFile, line)) {
		this->m_world.addObject(line);
	}
}
