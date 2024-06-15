#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/BubbleFactory.h"
#include "GameObjects/PhysicalObject.h"

class Bubble : public PhysicalObject
{
public:
	Bubble(const Data& ObjectData, b2World& world, const sf::Texture& texture);

private:
	b2BodyDef m_bodyDef;
	static bool m_registerit;
};