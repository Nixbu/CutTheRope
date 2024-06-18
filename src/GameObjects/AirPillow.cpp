#include "GameObjects/AirPillow.h"

AirPillow::AirPillow(const Data& ObjectData, const sf::Texture& texture) : NonClickableObject(ObjectData, texture)
{
}

bool AirPillow::m_registerit = FactoryManager::registerit("AirPillow",
	&AirPillowFactory::createObject);