#include "GameObjects/Hat.h"

Hat::Hat(const Data& ObjectData, const sf::Texture& texture) : NonClickableObject(ObjectData, texture)
{
}

bool Hat::m_registerit = FactoryManager::registerit("Hat",
	&HatFactory::createObject);