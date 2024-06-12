#pragma once
#include "Settings.h"
#include "GameObjects/NonPhysicalObject.h"

class Hat : public NonPhysicalObject
{
public:
	Hat(const Data& ObjectData, const sf::Texture& texture);
	virtual ~Hat() = default;

private:
};