#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/NonPhysicalObject.h"

class Omnom : public NonPhysicalObject
{
public:
	Omnom(const Data& ObjectData, b2World& world, const sf::Texture& texture);

private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};