#include "PlayingState.h"
#include "controller.h"




PlayingState::PlayingState()
{
}

void PlayingState::draw(sf::RenderWindow& window)
{
	// Draw level

	this->m_level.draw(window);

	// Draw menu
	this->m_menu.draw(window);
}

void PlayingState::handleClicks(const sf::Vector2f& mousePos)
{
	// Handle all level clicks
	this->m_level.handleClicks(mousePos);

	// Handle menu clicks
	this->m_menu.handleClicks(mousePos);
}

void PlayingState::update()
{

	this->m_level.update(); 
}

void PlayingState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void PlayingState::setLevel(const std::string& levelName)
{
	m_level.setLevelName(levelName);
	m_level.loadLevel();


	// TODO think about the reset level button,
	// return state of level but how?

}

void PlayingState::addButtons( Controller & controller)
{

	ResourceManager& manager = ResourceManager::getInstance();

	// level select button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(200, 200), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getLevelSelectionState())));


	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(400, 200), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller, controller.getMainState() )));

	// Reset button here?
	// this->m_menu.addButton(std::make_unique<LevelButton>(sf::Vector2f(400, 200), manager.getImage("PlayButton"),
		//MENU_BUTTON_DEFA_SIZE, Null));


}
