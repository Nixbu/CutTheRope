#pragma once
#include "GameState.h"
#include "ResourceManager.h"
#include "Menu.h"
#include "Commands/changeScreen.h"

class Controller;
class HelpState;
class LevelSelectState;

class MainState : public  GameState {
public:
	MainState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);	
	void addButtons(Controller& controller);
private:
	Menu m_menu;
	sf::Sprite m_bgImage;

	
};