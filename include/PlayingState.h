#pragma once

#include "GameState.h"
#include "Settings.h"
#include "ResourceManager.h"
#include "Menu.h"
#include <string>
#include "Level.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"
#include "Button.h"
#include "InterstitalState.h"

class Controller;


class PlayingState : public GameState
{
public:
	PlayingState(Controller& controller);
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void setLevel(const std::string & levelName);
	void addButtons();
	void setLevelNum(const int& levelNum);
private:
	int m_levelNum;
	Menu m_menu;
	Level m_level;
	Controller& m_controller;
	void changeToInterstital();
	
};

