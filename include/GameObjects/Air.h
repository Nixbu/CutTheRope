#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirFactory.h"
#include "GameObjects/NonClickableObject.h"

class Air : public NonClickableObject
{
public:
	Air(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update();
	const b2Vec2 getForce() const;


private:
	static bool m_registerit;
	b2Vec2 m_direction,
			m_force;
};