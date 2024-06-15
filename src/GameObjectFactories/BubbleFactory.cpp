#include "GameObjectFactories/BubbleFactory.h"

std::shared_ptr<GameObject> BubbleFactory::createObject(const Data& ObjectData, b2World& world, const sf::Texture& texture)
{
	return std::make_shared<Bubble>(ObjectData, world, texture);
}
