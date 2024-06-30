#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "ResourceManager.h"

class Controller;


// class WinState
/*
// WinState class represents the state of the game when the player passess the last level.
// It handles the display of the win screen and the interaction with buttons on this screen.
*/

class WinState : public GameState {
public:
	WinState(Controller& controller);
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update() {};
	virtual void handleFloating(const sf::Vector2f& mousePos);

private:
	void addButtons(Controller& controller);
	sf::Sprite m_backGround;
	Menu m_menu;
};