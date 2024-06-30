#pragma once
#include "GameState.h"
#include "ResourceManager.h"
#include "Menu.h"
#include "Commands/changeScreen.h"
#include "Commands/MusicCommand.h"

class Controller;
class HelpState;
class LevelSelectState;

/*
   The MainState class represents the main menu state of the game.
   It handles the main menu UI, including buttons for starting the game, accessing help,
   and selecting levels. This state responds to user input to navigate to different game states
   and manages the background image and other visual elements of the main menu.
*/

class MainState : public  GameState {
public:
	MainState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);	
	void addButtons(Controller& controller);
private:
	Menu m_menu;
	sf::Sprite m_bgImage;

	
};