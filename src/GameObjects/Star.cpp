#include "GameObjects/Star.h"

Star::Star(const Data& ObjectData, const sf::Texture& texture) : NonClickableObject(ObjectData, texture)
{
}


bool Star::m_registerit = FactoryManager::registerit("Star",
    &StarFactory::createObject);