#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "ResourceManager.h"
#include <memory>
#include "Commands/changeScreen.h"

class GameState;


class Button
{
public:
	Button(sf::Vector2f position, const sf::Texture& texture, sf::Vector2f scale,
		std::unique_ptr<Command> command);
	virtual ~Button() = default;
	void scale();
	bool isClicked(sf::Vector2f mousePosition) const;
	void draw(sf::RenderWindow& window) const;
	bool isFloatedOn(const sf::Vector2f& mousePosition) const;
	virtual void action() const;
	void Dscale();
	

private:
	sf::Sprite m_sprite;
	sf::Vector2f m_defSize, m_floatedSize;
	std::unique_ptr<Command> m_command;
};
