#pragma once


#include "MainState.h"

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
	//std::shared_ptr<LevelSelectionState> m_levelSelectiobState;
	//std::shared_ptr<HelpState> m_helpState;
	//std::shared_ptr<PlayingState> m_playingState;
	//std::shared_ptr<CompletedLevelState> m_completedLevelState;

	void changeState(std::shared_ptr<GameState> newState);
};
