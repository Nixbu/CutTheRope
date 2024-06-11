#pragma once

#include "box2d/box2d.h"

class World
{
public:
	World();
private:
	b2World m_physicalWorld;
	
};