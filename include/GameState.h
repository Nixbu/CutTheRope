#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Settings.h"


/*
   The GameState class defines an abstract interface for different game states.
   Subclasses must implement methods for drawing, handling mouse clicks, updating state,
   and handling mouse floating events.
*/

class GameState {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void handleClicks(const sf::Vector2f& mousePos) = 0;
	virtual void update() = 0;
	virtual void handleFloating(const sf::Vector2f& mousePos) = 0;
	
	virtual ~GameState() = default;

private:
	
};