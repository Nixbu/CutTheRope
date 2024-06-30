#include "InterstitalState.h"
#include "Controller.h"
//======================================================
// Constructor
// Initializes an InterstitalState object with background and button setup between levels.
// Parameters:
// - currentLevelName: Name of the current level.
// - nextLevelNum: Number of the next level.
// - controller: Reference to the game's controller for state management.
//======================================================
InterstitalState::InterstitalState(const std::string& currentLevelName, const int& nextLevelNum, Controller& controller) :
	m_currentLevel(currentLevelName) , m_menu()
{
	auto& manager = ResourceManager::getInstance();
	auto& bgTexture = manager.getImage("BetweenLevelsBG");

	this->m_nextLevel = "level" + std::to_string(nextLevelNum) + ".txt";
	this->m_backGround.setTexture(bgTexture);

	this->addButtons(controller , nextLevelNum);
}
//======================================================
void InterstitalState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_backGround);
	this->m_menu.draw(window);
}
//======================================================
// Handle Clicks Function
// Passes mouse click positions to the menu to handle button clicks.
//======================================================
void InterstitalState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}
//======================================================
void InterstitalState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}
//======================================================
// Add Buttons Function
// Adds buttons for level selection, restart, and next level to the menu.
// Parameters:
// - controller: Reference to the game's controller for state management.
// - nextLevelNum: Number of the next level to play.
//======================================================
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

}
