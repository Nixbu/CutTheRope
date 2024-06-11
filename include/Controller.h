#pragma once


#include "MainState.h"
#include "LevelSelectState.h"
#include "PlayingState.h"
#include "LevelNotFoundException.h"
#include <iostream>

class GameState;


/**
 * Represents a controller for managing game menus and buttons.
 */

class Controller
{
public:
	Controller();
	void run();

private:	
	std::shared_ptr<MainState> m_mainState;
	std::shared_ptr<GameState> m_currentState;
	std::shared_ptr<LevelSelectState> m_levelSelectState;
	//std::shared_ptr<HelpState> m_helpState;
	std::shared_ptr<PlayingState> m_playingState;
	//std::shared_ptr<CompletedLevelState> m_completedLevelState;

	void changeState(state_t newState);
	void handleInput(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};
