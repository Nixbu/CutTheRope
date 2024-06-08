#pragma once

#include "GameState.h"
#include "Menu.h"
#include "PlayButton.h"

class MainState;

class LevelSelectState : public GameState {
public:
	LevelSelectState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual state_t handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
private:
	Menu m_menu;

	void addButtons();
};