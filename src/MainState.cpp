#include "MainState.h"
#include "LevelSelectState.h"
#include "controller.h"



MainState::MainState()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_bgImage.setTexture(manager.getImage("MainWindowBG"));
}

void MainState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void MainState::update()
{
}

void MainState::addButtons(Controller& controller)
{
	ResourceManager& manager = ResourceManager::getInstance();
 
	this->m_menu.addButton(std::make_unique<Button>(PLAY_BTN_POS, manager.getImage("PlayButton"), 
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller , controller.getLevelSelectionState())));

	this->m_menu.addButton(std::make_unique<Button>(HELP_BUTTON_POS, manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getHelpState())));
}

void MainState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_bgImage);
	this->m_menu.draw(window);
}

void MainState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}