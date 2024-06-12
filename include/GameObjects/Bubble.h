#pragma once
#include "Settings.h"
#include "GameObjects/PhysicalObject.h"

class Bubble : public PhysicalObject
{
public:
	Bubble(const Data& ObjectData, b2World& world, const sf::Texture& texture);

private:
	b2BodyDef m_bodyDef;
};