#pragma once

#include <unordered_map>
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "FileException.h"
#include "WrongInputException.h"
#include "TimeException.h"

/**
 * Represents a menu containing buttons for user interaction.
 */

class Menu
{
public:
	Menu();
	~Menu() = default;

	void addButton(std::unique_ptr<Button> button, std::string name);
	void draw(sf::RenderWindow& window) const;
	void handleClicks(const sf::Vector2f& mousePos, sf::RenderWindow& window,
		GameButtonFlags_t& flag) const;
	void handleFloating(const sf::Vector2f& mousePos);


private:
	std::unordered_map<std::string, std::unique_ptr<Button>> m_buttons;
};