#pragma once


#include "MainState.h"
#include "LevelSelectState.h"
#include "PlayingState.h"
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
	std::shared_ptr<MainState> getMainState();
	std::shared_ptr<LevelSelectState>  getLevelSelectionState();
	std::shared_ptr<PlayingState>  getPlayingState();
	void setCurrentState(std::shared_ptr<GameState> next);

private:	
	std::shared_ptr<MainState> m_mainState;
	std::shared_ptr<GameState> m_currentState;
	std::shared_ptr<LevelSelectState> m_levelSelectState;
	//std::shared_ptr<HelpState> m_helpState;
	std::shared_ptr<PlayingState> m_playingState;
	//std::shared_ptr<CompletedLevelState> m_completedLevelState;

	void handleInput(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};
