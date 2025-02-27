#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/ClickableObject.h"
#include "GameObjectFactories/AirFactory.h"
#include "Animations/Animation.h"
#include <thread>
#include <chrono>

/*
   class  AirPillow
   The AirPillow class represents a pillow that can be clicked on to trigger specific actions in the game.
   It extends ClickableObject and manages its own animation and interactions.
*/

class AirPillow : public ClickableObject
{
public:
	AirPillow(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual ~AirPillow() = default;
	virtual void handleClicked() override;
	virtual void update(sf::Time& deltaTime) override; 


private:
	static bool m_registerit;
	World& m_world;
	const Data m_data;
	Animation m_animation;
};