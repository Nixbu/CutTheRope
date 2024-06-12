#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/Omnom.h"


std::shared_ptr<GameObject> OmnomFactory::createObject(const Data& ObjectData, b2World& world, const sf::Texture& texture) const
{
	return std::make_shared<Omnom>(ObjectData, world, texture);
}
