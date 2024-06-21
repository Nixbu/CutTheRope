#include "GameObjectFactories/HatFactory.h"
#include "GameObjects/Hat.h"


std::shared_ptr<GameObject> HatFactory::createObject(const Data& ObjectData, World& world, const sf::Texture& texture)
{
	return std::make_shared<Hat>(ObjectData, world, texture);
}
