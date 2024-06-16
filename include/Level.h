#pragma once

#include <string>
#include <fstream>
#include "World.h"

class Level
{
public:
	Level();
	void loadLevel(std::string levelFileName);
	void draw(sf::RenderWindow& window) const;
	void update();
private:
	std::ifstream m_levelFile;
	World m_world;
	sf::Clock m_clock;
	float m_accumulator;

	void readLevel();


};