#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/GravityButtonFactory.h"
#include "GameObjects/ClickableObject.h"

class GravityButton: public ClickableObject
{
public:
	GravityButton(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update();
	virtual void handleClicked();

private:
	static bool m_registerit;
	b2World& m_world;
	sf::Vector2f m_currentGravity;
};