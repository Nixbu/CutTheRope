#include "Button.h"


//===================================================================
// ctor for button 
Button::Button(sf::Vector2f position, const sf::Texture& texture, sf::Vector2f scale)
	: m_sprite(), m_defSize(scale)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2));
	m_sprite.setScale(scale);
	m_floatedSize = sf::Vector2f(m_defSize.x * 1.2, m_defSize.y * 1.2);


}


//===================================================================
// function returns true if the button was pressed
bool Button::isClicked(sf::Vector2f mousePosition) const
{
	return this->m_sprite.getGlobalBounds().contains(mousePosition);
}

//===================================================================
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

//===================================================================
void Button::scale()
{
	this->m_sprite.setScale(m_floatedSize);
}
//==================================================================
void Button::Dscale()
{
	this->m_sprite.setScale(m_defSize);
}
//===================================================================
bool Button::isFloatedOn(const sf::Vector2f& mousePosition) const
{
	return this->m_sprite.getGlobalBounds().contains(mousePosition);
}

