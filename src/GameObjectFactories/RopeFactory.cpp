#include "GameObjectFactories/RopeFactory.h"
#include "GameObjects/Rope.h"

std::shared_ptr<GameObject> RopeFactory::createObject(const Data& ObjectData, World& world, const sf::Texture& texture)
{
	return std::make_shared<Rope>(ObjectData, world, texture);
}
