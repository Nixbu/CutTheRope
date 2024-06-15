#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/Candy.h"


std::shared_ptr<GameObject> CandyFactory::createObject(const Data& ObjectData, b2World& world,const sf::Texture& texture)
{
	return std::make_shared<Candy>(ObjectData, world, texture);
}
