#pragma once

#include <string>
#include <fstream>
#include "World.h"

class Level
{
public:
	Level();
	void loadLevel();
	void draw(sf::RenderWindow& window) const;
	void update();
	void handleClicks(const sf::Vector2f& mousePos);
	void setLevelName(const std::string& levelName);
	levelStatus_t getLevelStatus()const;
	void setLevelStatus(const levelStatus_t& status);
	std::string getLevelName()const;
	void resetStars();
	int getStars() const;
	void resetLevelGravity();
	void resetLevel();

private:
	std::string m_levelName;
	std::ifstream m_levelFile;
	World m_world;
	sf::Clock m_clock;
	float m_accumulator;
	void readLevel();
	levelStatus_t m_status;
	sf::Sprite m_levelBg;
};