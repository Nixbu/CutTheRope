#pragma once
#include "Settings.h"
#include "GameObjects/PhysicalObject.h"

class Candy : public PhysicalObject
{
public:
	Candy(const Data& data , b2World& world);
	
private:
	b2BodyDef m_bodyDef;
};