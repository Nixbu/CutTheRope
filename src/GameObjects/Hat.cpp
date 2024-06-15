#include "GameObjects/Hat.h"

Hat::Hat(const Data& ObjectData, const sf::Texture& texture) : NonPhysicalObject(ObjectData, texture)
{
}

bool Hat::m_registerit = FactoryManager::registerit("Hat",
	&HatFactory::createObject);