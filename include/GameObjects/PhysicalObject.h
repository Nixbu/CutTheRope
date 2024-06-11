#pragma once

#include "GameObjects/GameObject.h"
#include "box2d/box2d.h"
#include "Settings.h"

class PhysicalObject : public GameObject
{
public:
	PhysicalObject(const Data & data);
	void initBody(b2World& world, const b2BodyDef& bodyDef); 

	virtual ~PhysicalObject();
private:
	b2Body* m_body;	
};