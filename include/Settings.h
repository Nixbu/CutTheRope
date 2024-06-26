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

const unsigned int WINDOW_MANAGER_WIDTH = 1100,
WINDOW_MANAGER_HEIGHT = 850,
FRAME_DELAY_MS = 50,
MAX_SIZE = 100,
LEVELS = 3,
LEVEL_SELECT_ROWS_LEVELS = 1,
MAX_LEVELS_ROW_LEVEL_SELECT = 10;



const sf::Vector2f MENU_BUTTON_DEFA_SIZE = { 1.0f, 1.0f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
                            WINDOW_MANAGER_HEIGHT / 2 + 300 },
    BEWEEN_LEVEL_SCREEN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
                                WINDOW_MANAGER_HEIGHT / 2 + 300 };

const unsigned int LEVEL_BUTTON_SHIFT_X = MENU_BUTTON_DEFA_SIZE.x + 125,
LEVEL_BUTTON_SHIFT_Y = MENU_BUTTON_DEFA_SIZE.y + 200,
ROW_NUM_OF_LEVELS = 5;

const sf::Vector2i FIRST_BUTTON_POSITION = { 100, 300 };


const sf::Vector2f GRAVITY_WORLD(0.0f, -6.8f);

struct Data {
    sf::Vector2f m_pos;
    sf::Vector2f m_pos2;
    float m_angle;
    float m_angle2;
    std::string m_type;
    std::string m_subType;
};

const float SCALE = 30.0f,
TIME_STEP = 1.0 / 60.0f,
AIR_VELOCITY = 5.0f,
AIR_FORCE = 100.0f,
LIVING_AIR_TIME = 0.2f;


const b2Vec2 BUBBLE_VELOCITY(0.0f, 2.0f),
BUBBLE_FORCE(0.0f, 150.0f);


const enum levelStatus_t { Won, OnGoing, Lost };