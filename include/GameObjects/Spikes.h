#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/SpikesFactory.h"
#include "GameObjects/NonClickableObject.h"

/*
   The Spikes class represents a non-clickable spikes object in the game.
   It extends NonClickableObject and manages its own update behavior.
*/

class Spikes : public NonClickableObject
{
public:
	Spikes(const Data& ObjectData, World& world, const sf::Texture& texture);

private:
	static bool m_registerit;
};