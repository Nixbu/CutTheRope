#pragma once


#include "MainState.h"
#include "LevelSelectState.h"
#include "PlayingState.h"
#include <iostream>
#include "HelpState.h"

class GameState;


/*
   The Controller class manages game menus and states, handling transitions
   between different states and user input.
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
	std::shared_ptr<HelpState>  getHelpState();
	void closeWindow();


private:	
	std::shared_ptr<MainState> m_mainState;
	std::shared_ptr<GameState> m_currentState;
	std::shared_ptr<LevelSelectState> m_levelSelectState;
	std::shared_ptr<HelpState> m_helpState;
	std::shared_ptr<PlayingState> m_playingState;
	sf::Image m_windowIconImage;
	sf::RenderWindow m_window;

	void handleInput(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);


};
