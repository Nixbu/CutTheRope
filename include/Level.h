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
	void handleClicks(const sf::Vector2f& mousePosRelease);
	void setLevelName(const std::string& levelName);
	levelStatus_t getLevelStatus()const;
	void setLevelStatus(const levelStatus_t& status);
	std::string getLevelName()const;
	void resetStars();
	int getStars() const;
	void resetLevelGravity();
	void setMousePressPos(const sf::Vector2f& mousePos);
	void setMouseReleasePos(const sf::Vector2f& mousePos);
;
private:
	int m_stars;
	std::string m_levelName;
	std::ifstream m_levelFile;
	World m_world;
	sf::Clock m_clock;
	float m_accumulator;
	levelStatus_t m_status;
	sf::Sprite m_levelBg;
	sf::Vector2f m_pressPos,
				 m_releasePos;

	void readLevel();
	void initPosPress();
};