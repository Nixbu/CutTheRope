#pragma once

#include "GameObjects/GameObject.h"
#include "box2d/box2d.h"
#include "Settings.h"

class PhysicalObject : public GameObject
{
public:
	PhysicalObject(const Data& data, const sf::Texture& texture);
	void initBody(b2World& world, 
		const b2BodyDef& bodyDef,
		const b2FixtureDef& fixtureDef);
	virtual b2Body* getBody();
	void SetLinearVelocity(const b2Vec2 linearVelocity);
	void setToDynamic();

	virtual ~PhysicalObject();
private:
	b2Body* m_body;
};