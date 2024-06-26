#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/SpikesFactory.h"
#include "GameObjects/NonClickableObject.h"

class Spikes : public NonClickableObject
{
public:
	Spikes(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);

private:
	static bool m_registerit;
};