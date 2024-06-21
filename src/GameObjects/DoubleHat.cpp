#include "GameObjects/DoubleHat.h"

bool DoubleHat::m_registerit = FactoryManager::registerit("DoubleHat",
	&HatFactory::createObject);

DoubleHat::DoubleHat(const Data& ObjectData, World& world, const sf::Texture& texture) 
	: NonClickableObject(ObjectData, texture), m_whichBody(false)
{
	m_hat1 = std::dynamic_pointer_cast<Hat>(HatFactory::createObject(ObjectData, world, texture));
	m_hat2 = std::dynamic_pointer_cast<Hat>(HatFactory::createObject(ObjectData, world, texture));
}

void DoubleHat::update()
{
}


