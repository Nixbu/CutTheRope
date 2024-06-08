#include "LevelSelectState.h"
#include "MainState.h"

LevelSelectState::LevelSelectState(std::shared_ptr<MainState> mainState)
	: m_mainState(mainState)
{
	this->addButtons();
}

void LevelSelectState::draw(sf::RenderWindow& window)
{
}

std::shared_ptr<GameState> LevelSelectState::handleClicks(const sf::Vector2f& mousePos)
{
	return std::shared_ptr<GameState>();
}

void LevelSelectState::update()
{
}

void LevelSelectState::handleFloating(const sf::Vector2f& mousePos)
{
}

void LevelSelectState::addButtons()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<PlayButton>(sf::Vector2f(100, 100), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, m_mainState));
}
