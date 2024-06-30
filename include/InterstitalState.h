#pragma once

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "ResourceManager.h"

class Controller;

/*
   The InterstitalState class represents the state of the game between levels, showing interstitial information or options.
   It inherits from GameState and provides methods to draw the state, handle mouse clicks,
   and manage the transition to the next level or other actions.
*/

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