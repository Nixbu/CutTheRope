#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/StarFactory.h"
#include "GameObjects/NonClickableObject.h"


class Star : public NonClickableObject
{
public:
	Star(const Data& ObjectData, const sf::Texture& texture);
	virtual ~Star() = default;
	virtual void handleClicked() {};


private:
	static bool m_registerit;
};