#pragma once

#include "GameObjects/GameObject.h"
#include "box2d/box2d.h"

class PhysicalObject : public GameObject
{
public:
private:
	b2Body m_body;
	
};