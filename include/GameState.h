#pragma once
#include "Menu.h"



class GameState {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual std::shared_ptr<GameState> handleClicks(const sf::Vector2f& mousePos) = 0;
	void handleFloating(const sf::Vector2f& mousePos); 
	virtual ~GameState() = default;

private:
	Menu m_menu;
};