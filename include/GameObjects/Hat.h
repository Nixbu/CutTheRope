#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/HatFactory.h"
#include "GameObjects/NonPhysicalObject.h"

class Hat : public NonPhysicalObject
{
public:
	Hat(const Data& ObjectData, const sf::Texture& texture);
	virtual ~Hat() = default;

	virtual void handleClicked(World& world) {};


private:
	static bool m_registerit;
};