#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/NonClickableObject.h"

class Omnom : public NonClickableObject
{
public:
	Omnom(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);

private:
	static bool m_registerit;
};