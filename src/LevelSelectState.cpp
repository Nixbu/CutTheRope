#include "LevelSelectState.h"
#include "MainState.h"
#include "Controller.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"


LevelSelectState::LevelSelectState(Controller& controller)
{
	this->addButtons(controller);
}

void LevelSelectState::draw(sf::RenderWindow& window)
{
	this->m_menu.draw(window);
}

void LevelSelectState::handleClicks(const sf::Vector2f& mousePos)
{
	 this->m_menu.handleClicks(mousePos);
}

void LevelSelectState::update()
{
}

void LevelSelectState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void LevelSelectState::addButtons(Controller &controller)
{
	ResourceManager& manager = ResourceManager::getInstance();

	// mainstate button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(100, 100), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller, controller.getMainState()))); // TODO change button

	//level1 button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(100, 300), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<PlayLevel>(controller, controller.getPlayingState() ,"level1.txt"))); // TODO change button

	//this->m_menu.addButton(std::make_unique<SandboxButton>(sf::Vector2f(450, 450), manager.getImage("SandboxButton"),
		//MENU_BUTTON_DEFA_SIZE, SANDBOX)); // TODO change button
}
