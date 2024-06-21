#include "GameObjectFactories/DoubleHatFactory.h"
#include "GameObjects/DoubleHat.h"


std::shared_ptr<GameObject> DoubleHatFactory::createObject(const Data& ObjectData, World& world, const sf::Texture& texture)
{
	// TODO add reading logic
	return std::make_shared<DoubleHat>(ObjectData, world, texture);
}
