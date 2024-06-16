#include "Level.h"

Level::Level() : m_world(), m_accumulator(0)
{
}

void Level::loadLevel(std::string levelFileName)
{
	
	this->m_world.reset();
	// TODO add try catch
	m_levelFile.open(levelFileName);

	this->readLevel();

	m_levelFile.close();

	this->m_clock.restart();

}

void Level::draw(sf::RenderWindow& window) const
{
	this->m_world.draw(window);
}

void Level::update()
{
	this->m_world.handleCollisions();

	float deltaTime = m_clock.restart().asSeconds();
	m_accumulator += deltaTime;

	// Update the world if the accumulator exceeds the time step
	while (m_accumulator >= TIME_STEP) {
		m_world.update(TIME_STEP);
		m_accumulator -= TIME_STEP;
	}
}

void Level::readLevel()
{
	std::string line;

	while (std::getline(this->m_levelFile, line)) {
		this->m_world.addObject(line);
	}
}

