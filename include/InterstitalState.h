#pragma once

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "ResourceManager.h"

class Controller;

class InterstitalState : public GameState {
public:
	InterstitalState(const std::string& currentLevelName, const int& nextLevelNum , Controller& controller);
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update() {};
	virtual void handleFloating(const sf::Vector2f& mousePos);
	
private:
	void addButtons(Controller& controller , const int& nextLevelNum);
	sf::Sprite m_backGround;
	std::string m_currentLevel, m_nextLevel;
	Menu m_menu;
};