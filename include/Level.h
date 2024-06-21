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
private:
	std::string m_level;
	std::ifstream m_levelFile;
	World m_world;
	sf::Clock m_clock;
	float m_accumulator;
	void readLevel();
	levelStatus_t m_status;
};