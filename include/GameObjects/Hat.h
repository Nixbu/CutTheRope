#pragma once


#include "GameObjects/NonClickableObject.h"

class Hat : public NonClickableObject
{
public:
	Hat(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update();
private:
};