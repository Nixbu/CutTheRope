#include "GameObjects/AirPillow.h"

AirPillow::AirPillow(const Data& ObjectData, const sf::Texture& texture) : ClickableObject(ObjectData, texture)
{
}

bool AirPillow::m_registerit = FactoryManager::registerit("AirPillow",
	&AirPillowFactory::createObject);