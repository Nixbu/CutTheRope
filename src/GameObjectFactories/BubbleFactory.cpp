#include "GameObjectFactories/BubbleFactory.h"
#include "GameObjects/Bubble.h"


std::shared_ptr<GameObject> BubbleFactory::createObject(const Data& ObjectData, b2World& world, const sf::Texture& texture) const
{
	return std::make_shared<Bubble>(ObjectData, world, texture);
}
