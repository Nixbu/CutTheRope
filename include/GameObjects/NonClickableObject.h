#pragma once

#include "GameObjects/GameObject.h"
#include "Settings.h"


/*
   The NonClickableObject class represents a base class for non-clickable game objects.
   It inherits from GameObject and provides basic functionality for non-interactive objects.
*/

class NonClickableObject : public GameObject
{
public:
	NonClickableObject(const Data& data, const sf::Texture& texture);
private:

};