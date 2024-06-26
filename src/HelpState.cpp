#include "HelpState.h"
#include "Controller.h"


HelpState::HelpState()
{
	ResourceManager& manager = ResourceManager::getInstance();
	this->m_bgImage.setTexture(manager.getImage("HelpStateBG"));
}

void HelpState::draw(sf::RenderWindow& window)
{
	window.draw(this->m_bgImage);
	this->m_menu.draw(window);
}

void HelpState::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_menu.handleClicks(mousePos);
}

void HelpState::handleFloating(const sf::Vector2f& mousePos)
{
	this->m_menu.handleFloating(mousePos);
}

void HelpState::addButtons(Controller& controller)
{
	auto& manager = ResourceManager::getInstance();
	this->m_menu.addButton(std::make_unique<Button>(sf::Vector2f(60, 60), manager.getImage("ReturnButton"),
		MENU_BUTTON_DEFA_SIZE,
		std::make_unique<ChangeScreen>(controller, controller.getMainState())));
}
