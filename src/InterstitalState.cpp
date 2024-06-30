#include "InterstitalState.h"
#include "Controller.h"

InterstitalState::InterstitalState(const std::string& currentLevelName, const int& nextLevelNum, Controller& controller) :
	m_currentLevel(currentLevelName) , m_menu()
{
	auto& manager = ResourceManager::getInstance();
	auto& bgTexture = manager.getImage("BetweenLevelsBG");

	this->m_nextLevel = "level" + std::to_string(nextLevelNum) + ".txt";
	this->m_backGround.setTexture(bgTexture);

	this->addButtons(controller , nextLevelNum);
}

void InterstitalState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_backGround);
	this->m_menu.draw(window);
}

void InterstitalState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}

void InterstitalState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void InterstitalState::addButtons(Controller& controller , const int& nextLevelNum)
{
	auto& manager = ResourceManager::getInstance();


	// level select button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(WINDOW_MANAGER_WIDTH /2 - 60 , WINDOW_MANAGER_HEIGHT / 2 +100 ),
		manager.getImage("ReturnToLevelsButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getLevelSelectionState())));

	// restart button 
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(WINDOW_MANAGER_WIDTH / 2 -160 , WINDOW_MANAGER_HEIGHT / 2 - 50), manager.getImage("ReplayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<PlayLevel>(controller, controller.getPlayingState(), this->m_currentLevel, nextLevelNum - 1))); // TODO change button

	// next level button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(WINDOW_MANAGER_WIDTH / 2 + 40 , WINDOW_MANAGER_HEIGHT / 2 - 50), manager.getImage("NextLevelButton"), // texture
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<PlayLevel>(controller, controller.getPlayingState(), this->m_nextLevel, nextLevelNum)));

	this->m_menu.addButton(std::make_unique<Button>(MUTE_BUTTON_POS, manager.getImage("UnmuteMusicButton"),
		SMALL_MENU_BUTTON_DEFA_SIZE,
		std::make_unique<MusicCommand>()));


}
