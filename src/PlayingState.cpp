#include "PlayingState.h"
#include "controller.h"



//=============================================================
// Constructor initializes the PlayingState with a controller and sets initial level number to 0.
PlayingState::PlayingState(Controller& controller) : m_controller(controller) , m_levelNum(0)
{
}
//=============================================================
// Draws the current state onto the provided SFML window.
void PlayingState::draw(sf::RenderWindow& window)
{

	this->m_level.draw(window);
	this->m_menu.draw(window);
}
//=============================================================
// Handles mouse clicks based on their position on the window.
void PlayingState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_level.handleClicks(mousePos);
	this->m_menu.handleClicks(mousePos);
}
//=============================================================
// Updates the state of the game based on the current level status.
void PlayingState::update()
{
	switch (this->m_level.getLevelStatus()) {
		case OnGoing:
			this->m_level.update();
			break;
		case Lost:
			this->m_level.resetLevel();
			this->m_level.loadLevel();
			break;
		case Won:			
			this->handleLevelPassing();
			break;
	} 
}
//=============================================================
// Handles floating interactions based on mouse position.
void PlayingState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}
//=============================================================
// Sets the current level by its name.
void PlayingState::setLevel(const std::string& levelName)
{
	m_level.resetLevel();
	m_level.setLevelName(levelName);
	m_level.loadLevel();

}
//=============================================================
// Adds buttons to the menu associated with the state.
void PlayingState::addButtons()
{

	ResourceManager& manager = ResourceManager::getInstance();

	// main state button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(50,70), manager.getImage("ReturnHomeButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(this->m_controller, this->m_controller.getMainState() )));

	// level select button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(150, 70), manager.getImage("PlayingToLevelSelectButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(this->m_controller, this->m_controller.getLevelSelectionState())));

	// Reset button
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(250, 70), manager.getImage("ResetLevelButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ResetLevel>(this->m_controller.getPlayingState())));
}
//=============================================================
// Sets the current level number.
void PlayingState::setLevelNum(const int& levelNum)
{
	this->m_levelNum = levelNum;
}
//=============================================================
// Changes the current state to the win state.
void PlayingState::changeToWinState()
{
	std::shared_ptr<WinState> winState = std::make_shared<WinState>(this->m_controller);
	this->m_controller.setCurrentState(winState);
}
//=============================================================
// Sets the mouse press position for the current level.
void PlayingState::MousePressPos(const sf::Vector2f& mousePos)
{
	this->m_level.setMousePressPos(mousePos);
}
//=============================================================
// Reloads the current level by resetting and loading it again.
void PlayingState::reloadLevel()
{
	this->m_level.resetLevel();
	this->m_level.loadLevel();
}
//=============================================================
// Changes the current state to the interstitial state for the next level.
void PlayingState::changeToInterstital()
{
	this->m_levelNum++;
	std::shared_ptr<InterstitalState> interState = std::make_shared<InterstitalState>(this->m_level.getLevelName(),
		this->m_levelNum, this->m_controller);
	this->m_controller.setCurrentState(interState);
}
//=============================================================
// Handles the logic for passing levels based on completion time.
void PlayingState::handleLevelPassing()
{
	if (this->m_level.getWorldTime() > ANIMATION_TIME) {
		this->m_controller.getLevelSelectionState()->setLevelButtonImg(this->m_level.getStars(), this->m_levelNum);
		this->m_level.resetLevel();


		// End of the levels
		if (this->m_levelNum == this->m_controller.getLevelSelectionState()->getNumOfLevels()) {
			this->changeToWinState();
		}
		// Another Level
		else {
			this->changeToInterstital();
		}
	}
	else
	{
		this->m_level.update();
	}
}
