#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <box2d/box2d.h>
#include <cmath>


/*
* this is a settings file for the constant values of the game.
* it also contains some utility func declarations.
*/

// Convert degrees to radians
constexpr float DEG2RAD = 0.0174532925f;

//utility functions declarations
b2Vec2 angleToDirection(float angle);
float angleToRadians(float angle);

//costume settings
const unsigned int WINDOW_MANAGER_WIDTH = 1100,
WINDOW_MANAGER_HEIGHT = 850,
FRAME_DELAY_MS = 50,
MAX_SIZE = 100;

// Object Sizes
const sf::Vector2f AIR_PILLOW_SIZE = { 119 , 127 },
                    OMNOM_SIZE = { 130 ,146 },
                    BUBBLE_SIZE = { 110, 96 };


// button sizes and positions
const sf::Vector2f MENU_BUTTON_DEFA_SIZE = { 1.0f, 1.0f },
SMALL_MENU_BUTTON_DEFA_SIZE = {0.5f, 0.5f},
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
                            WINDOW_MANAGER_HEIGHT / 2 + 150 },
    BEWEEN_LEVEL_SCREEN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
                                WINDOW_MANAGER_HEIGHT / 2 + 300 },
    HELP_BUTTON_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
                            WINDOW_MANAGER_HEIGHT / 2 + 250 },
    EXIT_BUTTON_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
                            WINDOW_MANAGER_HEIGHT / 2 + 350 },
    MUTE_BUTTON_POS = { 100, 800 },
    LEVEL_MUTE_BUTTON_POS = {350, 75};

// shifting buttons fonts and positions
const unsigned int LEVEL_BUTTON_SHIFT_X = MENU_BUTTON_DEFA_SIZE.x + 125,
LEVEL_BUTTON_SHIFT_Y = MENU_BUTTON_DEFA_SIZE.y + 200,
ROW_NUM_OF_LEVELS = 5, ANIMATION_TIME = 2,
LEVEL_BUTTON_FONT_SHIFT_X = 10,
LEVEL_BUTTON_FONT_SHIFT_Y = 60;

// the first level button position
const sf::Vector2i FIRST_BUTTON_POSITION = { 300, 300 };

// gravity of the b2world
const sf::Vector2f GRAVITY_WORLD(0.0f, -6.8f);

//stract cnteins the data of each object
struct Data {
    sf::Vector2f m_pos;
    sf::Vector2f m_pos2;
    float m_angle;
    float m_angle2;
    std::string m_type;
    std::string m_subType;
    std::string m_length;
};

const float SCALE = 30.0f, // scailling of the box2d to pixels
TIME_STEP = 1.0 / 60.0f, // time step for box2d
AIR_VELOCITY = 5.0f, // speed of the air object
AIR_FORCE = 100.0f, // power of the air object
LIVING_AIR_TIME = 0.2f, 
EXTENSION_CUT_LENGTH = 25.0f;

// bubble settings
const b2Vec2 BUBBLE_VELOCITY(0.0f, 2.0f),
BUBBLE_FORCE(0.0f, 150.0f);

//enums to update the game status
const enum levelStatus_t { Won, OnGoing, Lost };