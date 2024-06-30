#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/NonClickableObject.h"

/*
   class Candy
   The Candy class represents a non-clickable candy object in the game.
   It extends NonClickableObject and manages its own update behavior.
*/

class Candy : public NonClickableObject
{
public:
	Candy(const Data& ObjectData, World& world, const sf::Texture& texture);

private:
	static bool m_registerit;
};