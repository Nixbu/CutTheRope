#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/PhysicalObject.h"

class Omnom : public PhysicalObject
{
public:
	Omnom(const Data& ObjectData, b2World& world, const sf::Texture& texture);

private:
	b2BodyDef m_bodyDef;
	static bool m_registerit;
};