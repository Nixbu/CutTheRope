#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/NonClickableObject.h"

class Candy : public NonClickableObject
{
public:
	Candy(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	virtual void update();

	
private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};