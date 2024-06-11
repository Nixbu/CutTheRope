#pragma once

#include <string>
#include <fstream>

class Level
{
public:
	Level();
	void loadLevel(std::string levelFileName);

private:
	std::ifstream m_levelFile;

	void readLevel();
};