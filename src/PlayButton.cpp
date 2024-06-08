#include "PlayButton.h"


PlayButton::PlayButton(sf::Vector2f position, const sf::Texture& texture, sf::Vector2f scale,
    std::shared_ptr<GameState> state)
    : Button(position, texture, scale, state) {}


std::shared_ptr<GameState> PlayButton::action() const
{
	return this->getState();
}