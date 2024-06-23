#include "LevelSelectState.h"
#include "MainState.h"
#include "Controller.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"


LevelSelectState::LevelSelectState() : m_levelPlaylist("levelPlaylist.txt")
{
	
}

void LevelSelectState::draw(sf::RenderWindow& window)
{
	this->m_levelButtons.draw(window);
	this->m_options.draw(window);
}

void LevelSelectState::handleClicks(const sf::Vector2f& mousePos)
{
	 this->m_levelButtons.handleClicks(mousePos);
	 this->m_options.handleClicks(mousePos);
}

void LevelSelectState::update()
{
}

void LevelSelectState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_levelButtons.handleFloating(mousePos);
	this->m_options.handleFloating(mousePos);
}

void LevelSelectState::addButtons(Controller &controller)
{
	ResourceManager& manager = ResourceManager::getInstance();

	// Add level buttons

	// MainState button
	this->m_options.addButton(std::make_unique<Button>(sf::Vector2f(100, 100), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller, controller.getMainState()))); // TODO change button

	// TODO Add option buttons like Silence game etc
	/*this->m_options.addButton(std::make_unique<Button>(sf::Vector2f(?, ?), manager.getImage("SilenceButton"),
		size?,
		std::make_unique<SilenceGame>(parmeters needed?)));*/


	// Add level buttons
	

	std::ifstream levelPlaylist(m_levelPlaylist);
	std::string line;
	int levelNum = 1;
	auto position = FIRST_BUTTON_POSITION;
	const int buttonsPerRow = ROW_NUM_OF_LEVELS;  // Number of buttons per row
	bool open = false;

	while (std::getline(levelPlaylist, line))
	{
		if (levelNum == 1)
		{
			// Add the level button
			this->m_levelButtons.addButton(std::make_unique<Button>(
				sf::Vector2f(position),
				manager.getImage("0 Stars"),
				MENU_BUTTON_DEFA_SIZE,
				std::make_unique<PlayLevel>(controller, controller.getPlayingState(), line, levelNum, open)
			));
		}
		else
		{
			// Add the level button
			this->m_levelButtons.addButton(std::make_unique<Button>(
				sf::Vector2f(position),
				manager.getImage("LockedLevel"),
				MENU_BUTTON_DEFA_SIZE,
				std::make_unique<PlayLevel>(controller, controller.getPlayingState(), line, levelNum, open)
			));
		}

		// Update the position for the next button
		levelNum++;
		position.x += LEVEL_BUTTON_SHIFT_X;

		// Move to the next row if necessary
		if (levelNum % buttonsPerRow == 1) { // After buttonsPerRow buttons, move to the next row
			position.x = FIRST_BUTTON_POSITION.x; // Reset to the first column
			position.y += LEVEL_BUTTON_SHIFT_Y;   // Move down to the next row
		}
	}


	
}

void LevelSelectState::addLevelButtons()
{
	
	ResourceManager& manager = ResourceManager::getInstance();

	
}
void LevelSelectState::setLevelButtonImg(int stars, int levelNum)
{
	auto& resourceManager = ResourceManager::getInstance();

	auto textureName = std::to_string(stars) + " Stars";
	auto& texture = resourceManager.getImage(textureName);

	this->m_levelButtons.changeSpriteToButton(levelNum , texture);
}

int LevelSelectState::getNumOfLevels() const
{
	return m_levelButtons.getNumOfButtons();
}
