#include "WinState.h"
#include "Controller.h"
// Constructor for WinState.
// Initializes the background sprite with the win background image and adds buttons to the menu.
WinState::WinState(Controller& controller) 
{
	auto& manager = ResourceManager::getInstance();
	auto& bgTexture = manager.getImage("WinBG");
	this->m_backGround.setTexture(bgTexture);

	this->addButtons(controller);
}
//=======================================================================
// Draws the win state by drawing the background and menu onto the provided window.
void WinState::draw(sf::RenderWindow& window)
{	
	window.draw(this->m_backGround);
	this->m_menu.draw(window);
}
//=======================================================================
// Handles mouse click events by passing the mouse position to the menu's click handler.
void WinState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}
//=======================================================================
// Handles mouse hover events by passing the mouse position to the menu's floating handler.
void WinState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}
//=======================================================================
// Adds buttons to the win state menu. 
// This includes the return button that changes the screen back to the main state
void WinState::addButtons(Controller& controller)
{
	auto& manager = ResourceManager::getInstance();

	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(50, 50), manager.getImage("ReturnButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getMainState())));
}
