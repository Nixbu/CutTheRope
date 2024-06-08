#pragma once

#include "Button.h"

class PlayButton : public Button
{
public:
	PlayButton(sf::Vector2f position, const sf::Texture& texture, sf::Vector2f scale,
		std::shared_ptr<GameState> state);

	virtual std::shared_ptr<GameState> action() const override;
private:
};