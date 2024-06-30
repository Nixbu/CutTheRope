#include "Level.h"

Level::Level() :   m_world(), m_accumulator(0),m_pressPos(-1.f,-1.f)
					,m_releasePos(-1.f,-1.f)
{
}

void Level::loadLevel()
{
	
	this->m_world.reset();
	
	m_levelFile.open(m_levelName);

	if (!m_levelFile)
	{
		throw std::runtime_error("Error: File Not Found");
	}

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

void Level::handleClicks(const sf::Vector2f& mousePosRelease)
{
	setMouseReleasePos(mousePosRelease);

	std::pair<sf::Vector2f, sf::Vector2f> mousePos(m_pressPos, m_releasePos);

	this->m_world.handleClicks(mousePos);

	initPosPress();
}
void Level::setLevelName(const std::string& levelName)
{
	this->m_levelName = levelName;
}

levelStatus_t Level::getLevelStatus() const
{
	return this->m_world.getLevelStatus();
}

void Level::setLevelStatus(const levelStatus_t& status)
{
	this->m_world.setLevelStatus(status);
}

std::string Level::getLevelName() const
{
	return this->m_levelName;
}

void Level::resetStars()
{
	this->m_world.setStarsToZero();
}

int Level::getStars() const
{
	return this->m_world.getStars();
}

void Level::resetLevelGravity()
{
	this->m_world.resetGravity();
}

void Level::setMousePressPos(const sf::Vector2f& mousePos)
{
	this->m_pressPos = mousePos;
}
void Level::setMouseReleasePos(const sf::Vector2f& mousePos)
{
	this->m_releasePos = mousePos;
}

void Level::resetLevel()
{
	this->resetStars();
	this->resetLevelGravity();
	this->setLevelStatus(OnGoing);
}

double Level::getWorldTime() const
{
	return this->m_world.getTime();
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
void Level::initPosPress()
{
	this->m_pressPos = sf::Vector2f(-1.f, -1.f);
}
