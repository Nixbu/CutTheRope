#include "HelpState.h"
#include "Controller.h"

//======================================================
// Constructor
//======================================================
HelpState::HelpState()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_bgImage.setTexture(manager.getImage("HelpStateBG"));
}
//======================================================
// Draw Function
//======================================================
void HelpState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_bgImage);
	this->m_menu.draw(window);
}
//======================================================
// Handle Clicks Function
// Passes mouse click positions to the menu to handle button clicks.
//======================================================
void HelpState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}
//======================================================
// Handle Floating Function
// Passes mouse positions to the menu to handle button hovering effects.
//======================================================
void HelpState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}
//======================================================
// Add Buttons Function
// Adds a button to return to the main menu to the menu.
// Parameters:
// - controller: Reference to the game's controller for state management.
//=====================================================
void HelpState::addButtons(Controller& controller)
{
	auto& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(60, 60), manager.getImage("ReturnButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getMainState())));
}
