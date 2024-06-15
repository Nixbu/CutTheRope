#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/PhysicalObject.h"

class Candy : public PhysicalObject
{
public:
	Candy(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	
private:
	b2BodyDef m_bodyDef;
	static bool m_registerit;
};