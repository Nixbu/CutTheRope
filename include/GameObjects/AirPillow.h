#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/NonClickableObject.h"

class AirPillow : public NonClickableObject
{
public:
	AirPillow(const Data& ObjectData, const sf::Texture& texture);
	virtual ~AirPillow() = default;
	virtual void handleClicked() {};


private:
	static bool m_registerit;
};