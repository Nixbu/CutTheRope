#pragma once

#include "GameState.h"
#include "Menu.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"

class MainState;
class Controller;



class LevelSelectState : public GameState {
public:
	LevelSelectState(Controller& controller);
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f & mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
private:
	Menu m_menu;

	void addButtons(Controller& controller);
};