#include "GameObjects/ClickableObject.h"

ClickableObject::ClickableObject(const Data& data,const sf::Texture& texture) 
	:  GameObject(data ,texture)
	
{
}



ClickableObject::~ClickableObject()
{

}

bool ClickableObject::isClicked(const  std::pair<sf::Vector2f, sf::Vector2f>& mousePos)
{
	return this->getSprite().getGlobalBounds().contains(mousePos.second);
}
