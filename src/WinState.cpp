#include "WinState.h"
#include "Controller.h"

WinState::WinState(Controller& controller)
{
	auto& manager = ResourceManager::getInstance();
	auto& bgTexture = manager.getImage("WinBG");

	this->addButtons(controller);
}

void WinState::draw(sf::RenderWindow& window)
{
	this->m_menu.draw(window);
	window.draw(this->m_backGround);
}

void WinState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}

void WinState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void WinState::addButtons(Controller& controller)
{
	auto& manager = ResourceManager::getInstance();

	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(100, 100), manager.getImage("PlayButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getMainState())));
}
