#pragma once
#include "Settings.h"
#include "Gameobjects/NonClickableObject.h"

class World;

/*
   The Hook class represents a non-clickable hook object in the game.
   It extends NonClickableObject and manages its own update behavior.
*/

class Hook : public NonClickableObject  {
public:
	Hook(const Data& data, World& world, const sf::Texture& texture);
	
private:
	static bool m_registerIt;
};