#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/HatFactory.h"
#include "GameObjects/NonClickableObject.h"

class Hat : public NonClickableObject
{
public:
	Hat(const Data& ObjectData, const sf::Texture& texture);
	virtual void update() {};
private:
	static bool m_registerit;
};