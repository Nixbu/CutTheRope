#pragma once

#include <memory>
#include <SFML/Graphics.hpp>



class GameState {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual std::shared_ptr<GameState> handleClicks(const sf::Vector2f& mousePos) = 0;
	virtual void update() = 0;
	virtual void handleFloating(const sf::Vector2f& mousePos) = 0;
	
	virtual ~GameState() = default;

private:
	
};