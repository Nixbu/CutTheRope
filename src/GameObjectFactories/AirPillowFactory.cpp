#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/AirPillow.h"


std::shared_ptr<GameObject> AirPillowFactory::createObject(const Data& ObjectData,
	b2World& world,
	const sf::Texture& texture) const
{
	return std::make_shared<AirPillow>(ObjectData, texture);
}