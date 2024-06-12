#include "GameObjectFactories/SpikesFactory.h"
#include "GameObjects/Spikes.h"

std::shared_ptr<GameObject>SpikesFactory::createObject(const Data& ObjectData, 
	b2World& world, const sf::Texture& texture) const
{
	return std::make_unique<Spikes>(ObjectData, world, texture);
}