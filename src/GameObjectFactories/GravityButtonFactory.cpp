#include "GameObjectFactories/GravityButtonFactory.h"

std::shared_ptr<GameObject> GravityButtonFactory::createObject(const Data& ObjectData, World& world, const sf::Texture& texture)
{
	return std::make_shared<GravityButton>(ObjectData, world, texture);
}