#include "GameObjects/NonClickableObject.h"

//===================================================================
// Constructs a NonClickableObject using provided data and texture,
// initializing it as a GameObject.
//===================================================================
NonClickableObject::NonClickableObject(const Data& data, const sf::Texture& texture)
	: GameObject(data, texture)
{
}
