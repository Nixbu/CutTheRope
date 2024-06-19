#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <box2d/box2d.h>

const unsigned int WINDOW_MANAGER_WIDTH = 869,
WINDOW_MANAGER_HEIGHT = 867,
FRAME_DELAY_MS = 50;

const sf::Vector2f MENU_BUTTON_DEFA_SIZE = { 1.0f, 1.0f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
							WINDOW_MANAGER_HEIGHT / 2 + 300 };


struct Data {
	sf::Vector2f m_pos;
	std::string m_type;
};

const float SCALE = 30.0f,
TIME_STEP = 1.0 / 60.0f;

const b2Vec2 BUBBLE_VELOCITY(0.0f, 2.0f),
BUBBLE_FORCE(0.0f, 300.0f);
