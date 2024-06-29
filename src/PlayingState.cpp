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
			this->m_level.resetLevel();
			this->m_level.loadLevel();
			break;
		case Won:			
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
				break;
			}
			else
			{
				this->m_level.update();
				break;
			}
			
			
	} 
}

void PlayingState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void PlayingState::setLevel(const std::string& levelName)
{
	m_level.resetLevel();
	m_level.setLevelName(levelName);
	m_level.loadLevel();

}

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

void PlayingState::setLevelNum(const int& levelNum)
{
	this->m_levelNum = levelNum;
}

void PlayingState::changeToWinState()
{
	std::shared_ptr<WinState> winState = std::make_shared<WinState>(this->m_controller);
	this->m_controller.setCurrentState(winState);
}

void PlayingState::MousePressPos(const sf::Vector2f& mousePos)
{
	this->m_level.setMousePressPos(mousePos);
}

void PlayingState::reloadLevel()
{
	this->m_level.resetLevel();
	this->m_level.loadLevel();
}

void PlayingState::changeToInterstital()
{
	this->m_levelNum++;
	std::shared_ptr<InterstitalState> interState = std::make_shared<InterstitalState>(this->m_level.getLevelName(),
		this->m_levelNum, this->m_controller);
	this->m_controller.setCurrentState(interState);
}
