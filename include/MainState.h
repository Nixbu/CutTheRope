#pragma once
#include "GameState.h"
#include "ResourceManager.h"
#include "LevelSelectStateButton.h"
#include "Menu.h"

class HelpState;
class LevelSelectState;

class MainState : public  GameState {
public:
	MainState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual state_t handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	

private:
	Menu m_menu;

	void addButtons();
};