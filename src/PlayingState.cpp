#include "PlayingState.h"
#include "controller.h"




PlayingState::PlayingState(Controller& controller) : m_controller(controller) , m_levelNum(0)
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
	switch (this->m_level.getLevelStatus()) {
		case OnGoing:
			this->m_level.update();
			break;
		case Lost:
			this->m_level.setLevelStatus(OnGoing);
			this->m_level.loadLevel();
			break;
		case Won:
			this->changeToInterstital();
			
			//TODO
	} 
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

void PlayingState::addButtons()
{

	ResourceManager& manager = ResourceManager::getInstance();

	// level select button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(200, 200), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(this->m_controller, this->m_controller.getLevelSelectionState())));

	// main state button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(400, 200), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(this->m_controller, this->m_controller.getMainState() )));

	// Reset button here?
	// this->m_menu.addButton(std::make_unique<LevelButton>(sf::Vector2f(400, 200), manager.getImage("PlayButton"),
		//MENU_BUTTON_DEFA_SIZE, Null));


}

void PlayingState::setLevelNum(const int& levelNum)
{
	this->m_levelNum = levelNum;
}

void PlayingState::changeToInterstital()
{
	this->m_levelNum++;
	this->m_level.setLevelStatus(OnGoing);
	std::shared_ptr<InterstitalState> interState = std::make_shared<InterstitalState>(this->m_level.getLevelName(),
		this->m_levelNum, this->m_controller);
	this->m_controller.setCurrentState(interState);
}
