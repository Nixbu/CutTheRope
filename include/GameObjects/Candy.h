#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/ClickableObject.h"

class Candy : public ClickableObject
{
public:
	Candy(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	virtual void update();
	virtual void handleClicked() {};

	
private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};