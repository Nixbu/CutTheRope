#include "GameObjects/ClickableObject.h"
//===================================================================
// // Constructs a ClickableObject using the provided data and texture.
//===================================================================
ClickableObject::ClickableObject(const Data& data,const sf::Texture& texture) 
	:  GameObject(data ,texture)
	
{
}


//===================================================================
ClickableObject::~ClickableObject()
{
	// for abstract
}
//===================================================================
// Determines if the object has been clicked based on the provided mouse position.
// Checks if the mouse position is within the object's bounding box.
//===================================================================
bool ClickableObject::isClicked(const  std::pair<sf::Vector2f, sf::Vector2f>& mousePos)
{
	return this->getSprite().getGlobalBounds().contains(mousePos.second);
}
