#include "GameObjectFactories/StarFactory.h"
#include "GameObjects/Star.h"


std::shared_ptr<GameObject> StarFactory::createObject(const Data& ObjectData, 
														b2World& world, 
													const sf::Texture& texture)
{
	return std::make_shared<Star>(ObjectData, texture);
}
