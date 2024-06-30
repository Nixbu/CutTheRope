#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/NonClickableObject.h"

class Candy : public NonClickableObject
{
public:
	Candy(const Data& ObjectData, World& world, const sf::Texture& texture);

private:
	static bool m_registerit;
};