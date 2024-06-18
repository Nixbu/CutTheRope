#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/NonClickableObject.h"

class Omnom : public NonClickableObject
{
public:
	Omnom(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	virtual void handleClicked() {};


private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};