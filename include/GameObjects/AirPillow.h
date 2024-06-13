#pragma once
#include "Settings.h"
#include "GameObjects/NonPhysicalObject.h"

class AirPillow : public NonPhysicalObject
{
public:
	AirPillow(const Data& ObjectData, const sf::Texture& texture);
	virtual ~AirPillow() = default;

private:
};