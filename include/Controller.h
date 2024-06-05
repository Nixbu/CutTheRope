#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Settings.h"
#include "Button.h"
#include "PlayButton.h"
#include "LoadButton.h"
#include "ExitButton.h"
#include <memory>

/**
 * Represents a controller for managing game menus and buttons.
 */

class Controller
{
public:
	Controller();
	~Controller() = default;

	void addMenuButtons();
	void run();
private:
	Menu m_menu;
	sf::Sprite m_bgImge;
};
