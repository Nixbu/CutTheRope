#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/Omnom.h"


std::shared_ptr<GameObject> OmnomFactory::createObject(const Data& ObjectData,
	World& world,
	const sf::Texture& texture)
{
	return std::make_shared<Omnom>(ObjectData, world, texture);
}
