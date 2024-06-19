#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/AirPillow.h"

std::shared_ptr<GameObject> AirPillowFactory::createObject(const Data& ObjectData, World& world, const sf::Texture& texture)
{
	return std::make_shared<AirPillow>(ObjectData, world, texture);
}
