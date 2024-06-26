#include "Level.h"

Level::Level() :  m_status(OnGoing) , m_stars(0), m_world(m_status , m_stars), m_accumulator(0) 
{
}

void Level::loadLevel()
{
	
	this->m_world.reset();
	// TODO add try catch
	m_levelFile.open(m_levelName);

	this->readLevel();

	m_levelFile.close();

	this->m_clock.restart();

}

void Level::draw(sf::RenderWindow& window) const
{
	window.draw(this->m_levelBg);
	this->m_world.draw(window);
}

void Level::update()
{
	this->m_world.handleCollisions();

	sf::Time deltaTime = m_clock.restart();
	m_accumulator += deltaTime.asSeconds();

	// Update the world if the accumulator exceeds the time step
	while (m_accumulator >= TIME_STEP) {
		m_world.update(TIME_STEP, deltaTime);
		m_accumulator -= TIME_STEP;
	}
}

void Level::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_world.handleClicks(mousePos);
}
void Level::setLevelName(const std::string& levelName)
{
	this->m_levelName = levelName;
}

levelStatus_t Level::getLevelStatus() const
{
	return this->m_status;
}

void Level::setLevelStatus(const levelStatus_t& status)
{
	this->m_status = status;
}

std::string Level::getLevelName() const
{
	return this->m_levelName;
}

void Level::resetStars()
{
	this->m_stars = 0;
}

int Level::getStars() const
{
	return this->m_stars;
}

void Level::resetLevelGravity()
{
	this->m_world.resetGravity();
}

void Level::resetLevel()
{
	this->resetStars();
	this->resetLevelGravity();
	this->setLevelStatus(OnGoing);
}

void Level::readLevel()
{
	auto& manager = ResourceManager::getInstance();
	std::string line;
	std::getline(this->m_levelFile, line);
	this->m_levelBg.setTexture(manager.getImage("LevelBackground" + line));

	while (std::getline(this->m_levelFile, line)) {
		this->m_world.addObject(line);
	}
	
}

