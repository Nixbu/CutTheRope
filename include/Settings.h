#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>


const unsigned int WINDOW_MANAGER_WIDTH = 869,
WINDOW_MANAGER_HEIGHT = 867;

const sf::Vector2f MENU_BUTTON_DEFA_SIZE = { 1.0f, 1.0f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
							WINDOW_MANAGER_HEIGHT / 2 + 300 };

enum state_t{Null = 0, MAIN_STATE, LEVEL_SELECT_STATE, SANDBOX, LEVEL1};

struct Data {
	sf::Vector2f m_pos;
	std::string m_type;
};