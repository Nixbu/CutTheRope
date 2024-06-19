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

class Controller;


class PlayingState : public GameState
{
public:
	PlayingState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void setLevel(const std::string & levelName);
	void addButtons(Controller& controller);
private:
	Menu m_menu;
	Level m_level;
	
	
};

