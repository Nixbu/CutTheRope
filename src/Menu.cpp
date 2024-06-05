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
std::shared_ptr<GameState> Menu::handleClicks(const sf::Vector2f& mousePos,
	sf::RenderWindow& window) const
{
	for (const auto& btn : m_buttons)
	{
		if (btn->isClicked(mousePos))
		{
			return btn->action();
			
		}
	}
	return nullptr;
	/*catch (const FileException& e) {

		std::cerr << "File error: " << e.what() << std::endl;
	}
	catch (const WrongInputException& e) {
		std::cerr << "File format error: " << e.what() << std::endl;
	}
	catch (const TimeException& e) {
		std::cerr << "Time error: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}*/
	//TODO exceptions if needed

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
