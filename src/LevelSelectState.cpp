#include "LevelSelectState.h"
#include "MainState.h"
#include "Controller.h"
#include "Commands/changeScreen.h"
#include "Commands/PlayLevel.h"


LevelSelectState::LevelSelectState() : m_levelPlaylist("levelPlaylist.txt")
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_bgImage.setTexture(manager.getImage("LevelSelectionBg"));
}

void LevelSelectState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_bgImage);
	this->m_levelButtons.draw(window);
	this->m_options.draw(window);

	for (const auto& text : m_textLevelSelect)
	{
		window.draw(text);
	}
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

	// MainState button
	this->m_options.addButton(std::make_unique<Button>(sf::Vector2f(100, 100), manager.getImage("ReturnButton"),
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller, controller.getMainState())));

	this->m_options.addButton(std::make_unique<Button>(MUTE_BUTTON_POS, manager.getImage("UnmuteMusicButton"),
		SMALL_MENU_BUTTON_DEFA_SIZE,
		std::make_unique<MusicCommand>()));


	// Add level buttons
	

	std::ifstream levelPlaylist(m_levelPlaylist);
	std::string line, levelFileName, status;
	int levelNum = 1;
	auto position = FIRST_BUTTON_POSITION;
	const int buttonsPerRow = ROW_NUM_OF_LEVELS;  // Number of buttons per row
	const sf::Font& font = ResourceManager::getInstance().getFont("GoodDog");

	while (std::getline(levelPlaylist, line))
	{
		std::istringstream iss(line);

		iss >> levelFileName >> status;
		// Add the level button
		this->m_levelButtons.addButton(std::make_unique<Button>(
			sf::Vector2f(position),
			manager.getImage(status),
			MENU_BUTTON_DEFA_SIZE,
			std::make_unique<PlayLevel>(controller, controller.getPlayingState(), levelFileName, levelNum)
		));

		sf::Text text;
		text.setFont(font);
		text.setString(std::to_string(levelNum));
		text.setCharacterSize(80);
		text.setFillColor(sf::Color::White);
		text.setPosition(position.x - LEVEL_BUTTON_FONT_SHIFT_X,position.y - LEVEL_BUTTON_FONT_SHIFT_Y);

		m_textLevelSelect.push_back(text);
		// Update the position for the next button
		levelNum++;
		position.x += LEVEL_BUTTON_SHIFT_X;

		// Move to the next row if necessary
		if (levelNum % buttonsPerRow == 1) { 
			position.x = FIRST_BUTTON_POSITION.x; 
			position.y += LEVEL_BUTTON_SHIFT_Y;  
		}
	}
}

void LevelSelectState::setLevelButtonImg(int stars, int levelNum)
{
	auto& resourceManager = ResourceManager::getInstance();

	auto textureName = std::to_string(stars) + "Stars";
	auto& texture = resourceManager.getImage(textureName);

	this->m_levelButtons.changeSpriteToButton(levelNum , texture);
}

int LevelSelectState::getNumOfLevels() const
{
	return m_levelButtons.getNumOfButtons();
}

