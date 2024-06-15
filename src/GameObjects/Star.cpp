#include "GameObjects/Star.h"

Star::Star(const Data& ObjectData, const sf::Texture& texture) : NonPhysicalObject(ObjectData, texture)
{
}


bool Star::m_registerit = FactoryManager::registerit("Star",
    &StarFactory::createObject);