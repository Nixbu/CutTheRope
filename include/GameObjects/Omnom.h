#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/NonClickableObject.h"
#include "Animations/Animation.h"

/*
   The Omnom class represents a non-clickable object named Omnom in the game.
   It extends NonClickableObject and manages its own update behavior along with animations.
*/

class Omnom : public NonClickableObject
{
public:
	Omnom(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime) override;
	void setAnimationFlag(const bool& flag);

private:
	static bool m_registerit;
	Animation m_animation;
};