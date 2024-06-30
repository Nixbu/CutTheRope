#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/AirFactory.h"
#include "GameObjects/NonClickableObject.h"

/*
   class Air
   The Air class represents an air object in the game, extending NonClickableObject.
   It manages direction, force, and updates based on elapsed time.
*/

class Air : public NonClickableObject
{
public:
	Air(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);
	const b2Vec2 getForce() const;
	void  checkTime();


private:
	static bool m_registerit;
	b2Vec2 m_direction,
			m_force;
	sf::Clock m_clock;
};