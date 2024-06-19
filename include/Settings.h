#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <box2d/box2d.h>
#include <cmath>

// Convert degrees to radians
constexpr float DEG2RAD = 0.0174532925f;

b2Vec2 angleToDirection(float angle);
float angleToRadians(float angle);

const unsigned int WINDOW_MANAGER_WIDTH = 869,
WINDOW_MANAGER_HEIGHT = 867,
FRAME_DELAY_MS = 50;

const sf::Vector2f MENU_BUTTON_DEFA_SIZE = { 1.0f, 1.0f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
							WINDOW_MANAGER_HEIGHT / 2 + 300 };

enum state_t{Null = 0, MAIN_STATE, LEVEL_SELECT_STATE, SANDBOX, LEVEL1};

struct Data {
	sf::Vector2f m_pos;
	float m_angle;
	std::string m_type;
};

const float SCALE = 30.0f,
TIME_STEP = 1.0 / 60.0f,
AIR_VELOCITY = 10.0f;


const b2Vec2 BUBBLE_VELOCITY(0.0f, 2.0f),
BUBBLE_FORCE(0.0f, 300.0f);
