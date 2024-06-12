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
private:
	std::ifstream m_levelFile;
	World m_world;

	void readLevel();
};