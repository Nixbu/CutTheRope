#pragma once
#include "Settings.h"
#include "GameObjectFactories/HatFactory.h"
#include "GameObjects/NonClickableObject.h"
#include "GameObjects/Hat.h"

class Hat : public NonClickableObject
{
public:
	Hat(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update();
private:
	static bool m_registerit;
};