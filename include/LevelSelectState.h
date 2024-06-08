#pragma once

#include "GameState.h"
#include "Menu.h"
#include "PlayButton.h"

class MainState;

class LevelSelectState : public GameState {
public:
	LevelSelectState(std::shared_ptr<MainState> mainState);
	virtual void draw(sf::RenderWindow& window) override;
	virtual std::shared_ptr<GameState> handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
private:
	Menu m_menu;

	std::shared_ptr<MainState> m_mainState;

	void addButtons();
};