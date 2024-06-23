#pragma once

#include "GameState.h"
#include "Menu.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"
#include <sstream>

class MainState;
class Controller;



class LevelSelectState : public GameState {
public:
	LevelSelectState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f & mousePos);
	virtual void update();
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void addButtons(Controller& controller);
	void setLevelButtonImg(int stars, int what);
	int getNumOfLevels() const;
private:
	Menu m_levelButtons;
	Menu m_options;
	std::string m_levelPlaylist;


	void addLevelButtons();



	
};