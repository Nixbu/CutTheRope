#include "GameObjects/ClickableObject.h"

ClickableObject::ClickableObject(const Data& data,const sf::Texture& texture) 
	:  GameObject(data ,texture)
	
{
}



ClickableObject::~ClickableObject()
{

}

bool ClickableObject::isClicked(const sf::Vector2f& mousePos) const
{
	return this->getSprite().getGlobalBounds().contains(mousePos);
}
