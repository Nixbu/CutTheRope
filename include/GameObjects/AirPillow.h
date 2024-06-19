#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/ClickableObject.h"

class AirPillow : public ClickableObject
{
public:
	AirPillow(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual ~AirPillow() = default;
	virtual void handleClicked() override; //TODO
	virtual void update() override {}; // TODO


private:
	static bool m_registerit;
};