#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/StarFactory.h"
#include "GameObjects/NonClickableObject.h"
#include <thread>
#include <chrono>

/*
   The Star class represents a non-clickable star object in the game.
   It extends NonClickableObject and manages its own update behavior.
*/

class Star : public NonClickableObject
{
public:
	Star(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual ~Star() = default;


private:
	static bool m_registerit;
};