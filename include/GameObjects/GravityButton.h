#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/GravityButtonFactory.h"
#include "GameObjects/ClickableObject.h"
#include <thread> 
#include <chrono> 

/*
   The GravityButton class represents a clickable button that changes the gravity in the game.
   It extends ClickableObject and manages its own update and click handling.
*/

class GravityButton: public ClickableObject
{
public:
	GravityButton(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);
	virtual void handleClicked();

private:
	static bool m_registerit;
	b2World& m_world;
	sf::Vector2f m_currentGravity;
	float m_degree;
};