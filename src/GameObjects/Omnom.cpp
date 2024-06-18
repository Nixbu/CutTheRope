#include "GameObjects/Omnom.h"

Omnom::Omnom(const Data& ObjectData, World& world, const sf::Texture& texture) : 
    NonClickableObject(ObjectData, texture) 
{


}

bool Omnom::m_registerit = FactoryManager::registerit("Omnom",
    &OmnomFactory::createObject);