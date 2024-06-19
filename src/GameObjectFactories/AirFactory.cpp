#include "GameObjectFactories/AirFactory.h"

std::shared_ptr<GameObject> AirFactory::createObject(const Data& ObjectData, World& world, const sf::Texture& texture)
{
	return std::make_shared<Air>(ObjectData, world, texture);
}