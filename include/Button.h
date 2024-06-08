#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "ResourceManager.h"
#include <memory>

class GameState;

class Button
{
public:
	Button(sf::Vector2f position, const sf::Texture& texture, sf::Vector2f scale,
			std::shared_ptr<GameState> state);
	virtual ~Button() = default;
	void scale();
	bool isClicked(sf::Vector2f mousePosition) const;
	void draw(sf::RenderWindow& window) const;
	bool isFloatedOn(const sf::Vector2f& mousePosition) const;
	virtual std::shared_ptr<GameState> action() const = 0;
	void Dscale();
	std::shared_ptr<GameState> getState() const;

private:
	sf::Sprite m_sprite;
	sf::Vector2f m_defSize, m_floatedSize;
	std::shared_ptr<GameState> m_nextState;
};
