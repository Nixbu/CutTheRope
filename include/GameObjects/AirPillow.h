#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/ClickableObject.h"
#include "GameObjectFactories/AirFactory.h"
#include "Animations/Animation.h"
#include <thread>
#include <chrono>

class AirPillow : public ClickableObject
{
public:
	AirPillow(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual ~AirPillow() = default;
	virtual void handleClicked() override;
	virtual void update(sf::Time& deltaTime) override; // TODO animations


private:
	static bool m_registerit;
	World& m_world;
	const Data m_data;
	Animation m_animation;
	bool m_animating;
};