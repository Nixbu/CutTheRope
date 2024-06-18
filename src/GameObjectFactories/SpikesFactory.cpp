#include "GameObjectFactories/SpikesFactory.h"
#include "GameObjects/Spikes.h"

std::shared_ptr<GameObject>SpikesFactory::createObject(const Data& ObjectData, 
	World& world, const sf::Texture& texture)
{
	return std::make_shared<Spikes>(ObjectData, world, texture);
}