#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/ClickableObject.h"
#include "GameObjectFactories/AirFactory.h"

class AirPillow : public ClickableObject
{
public:
	AirPillow(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual ~AirPillow() = default;
	virtual void handleClicked() override; //TODO
	virtual void update() override {}; // TODO animations, maybe physics?


private:
	static bool m_registerit;
	World& m_world;
	const Data m_data;
};