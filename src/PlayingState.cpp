#include "PlayingState.h"

PlayingState::PlayingState()
{
}

void PlayingState::draw(sf::RenderWindow& window)
{
	// Draw level

	// this->m_level.draw(window);

	// Draw menu
	this->m_menu.draw(window);
}

state_t PlayingState::handleClicks(const sf::Vector2f& mousePos)
{
	// Handle all level clicks
	// this->m_level.handleClicks(mousePos);

	// Handle menu clicks
	return this->m_menu.handleClicks(mousePos);
}

void PlayingState::update()
{
}

void PlayingState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void PlayingState::setLevel(state_t levelState)
{

}

void PlayingState::addButtons()
{

	ResourceManager& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<LevelSelectStateButton>(sf::Vector2f(200, 200), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, LEVEL_SELECT_STATE));
	this->m_menu.addButton(std::make_unique<MainStateButton>(sf::Vector2f(400, 200), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, MAIN_STATE));

}
