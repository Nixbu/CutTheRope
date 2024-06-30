#include "Menu.h"

//======================================================
// Default constructor for Menu class.
Menu::Menu()
{
}

//======================================================
// Adds a button to the menu.
// Parameters:
// - button: A unique pointer to a Button object to be added.
void Menu::addButton(std::unique_ptr<Button>&& button)

{
	m_buttons.push_back(std::move(button));
}

//======================================================
// Draws all buttons in the menu on the provided window.
void Menu::draw(sf::RenderWindow& window) const
{

	for (const auto& btn : this->m_buttons)
	{
		btn->draw(window);
	}

}

//======================================================
// Handles mouse clicks on buttons within the menu.
void Menu::handleClicks(const sf::Vector2f& mousePos) const
{
	for (const auto& btn : m_buttons)
	{
		if (btn->isClicked(mousePos))
		{
			btn->action();
			break;

		}
	}
}
//======================================================
// Handles mouse hovering over buttons within the menu.
void Menu::handleFloating(const sf::Vector2f& mousePos)
{
	for (const auto& btn : this->m_buttons)
	{
		if (btn->isFloatedOn(mousePos))
		{
			btn->scale();
		}
		else
		{
			btn->Dscale();
		}
	}
}
//======================================================
// Changes the sprite texture of a button at a specified index.
void Menu::changeSpriteToButton(int idx, const sf::Texture& texture)
{
	this->m_buttons[idx - 1]->setSprite(texture);
}
//======================================================
// Returns the number of buttons currently in the menu.
int Menu::getNumOfButtons() const
{
	return m_buttons.size();
}
