#pragma once

#include "Button.h"
#include <memory>

/**
 * Represents a menu containing buttons for user interaction.
 */

class Menu
{
public:
	Menu();
	~Menu() = default;

	void addButton(std::unique_ptr<Button>&& button);
	void draw(sf::RenderWindow& window) const;
	void handleClicks(const sf::Vector2f& mousePos) const;
	void handleFloating(const sf::Vector2f& mousePos);


private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};