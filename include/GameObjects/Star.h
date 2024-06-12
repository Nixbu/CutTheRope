#pragma once
#include "Settings.h"
#include "GameObjects/NonPhysicalObject.h"

class Candy;

class Star : public NonPhysicalObject
{
public:
	Star(const Data& ObjectData, const sf::Texture& texture);
	virtual ~Star() = default;

private:
};