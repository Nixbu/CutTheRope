#pragma once

#include "ResourceManager.h"
#include "Menu.h"
#include "Commands/changeScreen.h"
#include <memory>

class Controller;

/*
   The HelpState class represents the state of the game when the player is viewing help or instructions.
   It inherits from GameState and provides methods to draw the state, handle mouse clicks,
   and add buttons specific to the help menu.
*/

class HelpState : public  GameState {
public:
	HelpState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update() {};
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void addButtons(Controller& controller);
private:
	Menu m_menu;
	sf::Sprite m_bgImage;


};