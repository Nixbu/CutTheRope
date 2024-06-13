#include "MainState.h"
#include "LevelSelectState.h"


MainState::MainState()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_bgImage.setTexture(manager.getImage("MainWindowBG"));
	this->addButtons();
}

void MainState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void MainState::update()
{
}

void MainState::addButtons()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<LevelSelectStateButton>(PLAY_BTN_POS, manager.getImage("PlayButton"), 
		MENU_BUTTON_DEFA_SIZE, LEVEL_SELECT_STATE));
}

void MainState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_bgImage);
	this->m_menu.draw(window);
}

state_t MainState::handleClicks(const sf::Vector2f& mousePos)
{
	return this->m_menu.handleClicks(mousePos);
}