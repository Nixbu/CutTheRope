#pragma once

#include "Button.h"
#include <memory>
#include <iostream>

/*
   The Menu class represents a collection of buttons for user interaction.
   It manages the lifecycle and behavior of these buttons, including adding new buttons,
   drawing them to the window, handling user clicks, and updating their appearance based on user interaction.
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
	void changeSpriteToButton(int idx, const sf::Texture& texture);
	int getNumOfButtons() const;
private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};