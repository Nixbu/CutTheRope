#pragma once

#include "GameState.h"
#include "Settings.h"
#include "ResourceManager.h"
#include "Menu.h"
#include "MainStateButton.h"
#include "LevelSelectStateButton.h"
#include "Level.h"
#include "LevelButton.h"

class PlayingState : public GameState
{
public:
	PlayingState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual state_t handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void setLevel(state_t levelState);
private:
	Menu m_menu;
	std::unordered_map<state_t, std::string> m_levelMap;
	Level m_level;
	void addButtons();
	
};

