#include "LevelSelectState.h"
#include "MainState.h"
#include "Controller.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"


LevelSelectState::LevelSelectState()
{
	
}

void LevelSelectState::draw(sf::RenderWindow& window)
{
	this->m_levelButtons.draw(window);
	this->m_options.draw(window);
}

void LevelSelectState::handleClicks(const sf::Vector2f& mousePos)
{
	 this->m_levelButtons.handleClicks(mousePos);
	 this->m_options.handleClicks(mousePos);
}

void LevelSelectState::update()
{
}

void LevelSelectState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_levelButtons.handleFloating(mousePos);
	this->m_options.handleFloating(mousePos);
}

void LevelSelectState::addButtons(Controller &controller)
{
	ResourceManager& manager = ResourceManager::getInstance();

	// mainstate button
	this->m_levelButtons.addButton(std::make_unique<Button>(sf::Vector2f(100, 100), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller, controller.getMainState()))); // TODO change button

	//level1 button
	this->m_levelButtons.addButton(std::make_unique<Button>(sf::Vector2f(100, 300), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<PlayLevel>(controller, controller.getPlayingState() ,"level1.txt" , 1))); // TODO change button

	// TODO Add option buttons like Silence game etc
	/*this->m_options.addButton(std::make_unique<Button>(sf::Vector2f(?, ?), manager.getImage("SilenceButton"),
		size?,
		std::make_unique<SilenceGame>(parmeters needed?)));*/
}
