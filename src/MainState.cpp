#include "MainState.h"
#include "LevelSelectState.h"

void MainState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void MainState::update()
{
}

MainState::MainState(std::shared_ptr<LevelSelectState> levelSelectState)
	: m_levelSelectState(levelSelectState)
{
	this->addButtons();
}

void MainState::addButtons()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<PlayButton>(PLAY_BTN_POS, manager.getImage("PlayButton"), 
		MENU_BUTTON_DEFA_SIZE, m_levelSelectState));
}

void MainState::draw(sf::RenderWindow& window)
{
	this->m_menu.draw(window);
}

std::shared_ptr<GameState> MainState::handleClicks(const sf::Vector2f& mousePos)
{
	return this->m_menu.handleClicks(mousePos);
}