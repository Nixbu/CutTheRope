#include "LevelSelectState.h"
#include "MainState.h"

LevelSelectState::LevelSelectState()
{
	this->addButtons();
}

void LevelSelectState::draw(sf::RenderWindow& window)
{
	this->m_menu.draw(window);
}

state_t LevelSelectState::handleClicks(const sf::Vector2f& mousePos)
{
	return this->m_menu.handleClicks(mousePos);
}

void LevelSelectState::update()
{
}

void LevelSelectState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void LevelSelectState::addButtons()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<MainStateButton>(sf::Vector2f(100, 100), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, MAIN_STATE)); // TODO change button
	this->m_menu.addButton(std::make_unique<LevelButton>(sf::Vector2f(100, 300), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, LEVEL1)); // TODO change button
	this->m_menu.addButton(std::make_unique<SandboxButton>(sf::Vector2f(450, 450), manager.getImage("SandboxButton"),
		MENU_BUTTON_DEFA_SIZE, SANDBOX)); // TODO change button
}
