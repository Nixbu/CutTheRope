#pragma once


#include "GameObjects/NonClickableObject.h"

/*
   The Hat class represents a non-clickable hat object in the game.
   It extends NonClickableObject and manages its own update behavior.
*/

class Hat : public NonClickableObject
{
public:
	Hat(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);
private:
};