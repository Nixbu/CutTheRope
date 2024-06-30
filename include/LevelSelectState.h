#pragma once

#include "GameState.h"
#include "Menu.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"
#include <sstream>

class MainState;
class Controller;

/*
   The LevelSelectState class represents the state where players can select levels to play.
   It manages the UI for level selection, handles user input to choose levels, and updates
   the display accordingly. This state also includes functionality to add buttons dynamically
   based on the number of levels and their completion status.
*/

class LevelSelectState : public GameState {
public:
	LevelSelectState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f & mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void addButtons(Controller& controller);
	void setLevelButtonImg(int stars, int levelNum);
	int getNumOfLevels() const;
private:
	Menu m_levelButtons;
	Menu m_options;
	sf::Sprite m_bgImage;
	std::vector <sf::Text> m_textLevelSelect;
	void setButtonFont( sf::Text& text, const sf::Vector2i& pos , const int & levelNum);
};