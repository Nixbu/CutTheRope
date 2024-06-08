#pragma once
#include "GameState.h"
#include "ResourceManager.h"
#include "PlayButton.h"
#include "Menu.h"

class HelpState;
class LevelSelectState;

class MainState : public  GameState {
public:
	MainState(std::shared_ptr<LevelSelectState> levelSelectState);
	virtual void draw(sf::RenderWindow& window) override;
	virtual std::shared_ptr<GameState> handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	

private:
	Menu m_menu;
	std::shared_ptr<LevelSelectState> m_levelSelectState;

	void addButtons();
};