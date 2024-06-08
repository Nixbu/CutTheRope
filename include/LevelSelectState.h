#pragma once

#include "GameState.h"

class LevelSelectState : public GameState {
public:
	virtual void draw(sf::RenderWindow& window) override;
	virtual std::shared_ptr<GameState> handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
private:
};