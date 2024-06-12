#pragma once
#include "GameObjectFactory.h"


class Candy;

class CandyFactory :public  GameObjectFactory {
public:

	virtual std::unique_ptr<PhysicalObject> createPhysicalObject(const Data& ObjectData, b2World& world) const;
	virtual std::unique_ptr<NonPhysicalObject> createNonPhysicalObject(const Data& ObjectData, b2World& world) const {};
private:

};