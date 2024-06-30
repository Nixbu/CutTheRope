#include "MainState.h"
#include "LevelSelectState.h"
#include "controller.h"


//======================================================
// MainState Constructor
// Initializes the main state with background image and music.
//======================================================
MainState::MainState()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_bgImage.setTexture(manager.getImage("MainWindowBG"));
}
//======================================================
// Handle Floating Function
// Passes the mouse position to the menu to handle floating effects.
//======================================================
void MainState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}
//======================================================
void MainState::update()
{
}
//======================================================
// Add Buttons Function
// Adds buttons to the menu for play and help functionalities.
// Parameters:
// - controller: Reference to the game controller for state transitions.
//======================================================
void MainState::addButtons(Controller& controller)
{
	ResourceManager& manager = ResourceManager::getInstance();
 
	this->m_menu.addButton(std::make_unique<Button>(PLAY_BTN_POS, manager.getImage("PlayButton"), 
		MENU_BUTTON_DEFA_SIZE, 
		std::make_unique<ChangeScreen>(controller , controller.getLevelSelectionState())));

	this->m_menu.addButton(std::make_unique<Button>(HELP_BUTTON_POS, manager.getImage("HelpButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getHelpState())));

	this->m_menu.addButton(std::make_unique<Button>(MUTE_BUTTON_POS, manager.getImage("UnmuteMusicButton"),
		SMALL_MENU_BUTTON_DEFA_SIZE,
		std::make_unique<MusicCommand>()));
}
//======================================================
// Draw Function
// Draws the background image and menu components to the window.
// Parameters:
// - window: Reference to the SFML render window to draw on.
//======================================================
void MainState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_bgImage);
	this->m_menu.draw(window);
}
//======================================================
// Handle Clicks Function
// Passes mouse clicks to the menu for processing.
// Parameters:
// - mousePos: Position of the mouse click.
//======================================================
void MainState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}