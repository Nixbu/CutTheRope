#include "Menu.h"


Menu::Menu()
{
}


void Menu::addButton(std::unique_ptr<Button>&& button)

{
	m_buttons.push_back(std::move(button));
}

//======================================================
void Menu::draw(sf::RenderWindow& window) const
{

	for (const auto& btn : this->m_buttons)
	{
		btn->draw(window);
	}

}

//======================================================
void Menu::handleClicks(const sf::Vector2f& mousePos) const
{
	try
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
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

//======================================================
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

void Menu::changeSpriteToButton(int idx, const sf::Texture& texture)
{
	this->m_buttons[idx - 1]->setSprite(texture);
}

int Menu::getNumOfButtons() const
{
	return m_buttons.size();
}
