#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/StarFactory.h"
#include "GameObjects/NonClickableObject.h"
#include <thread>
#include <chrono>


class Star : public NonClickableObject
{
public:
	Star(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual ~Star() = default;
	virtual void update(sf::Time& deltaTime) ;


private:
	static bool m_registerit;
};