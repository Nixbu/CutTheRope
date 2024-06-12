#pragma once
#include <memory>
#include "Settings.h"
#include "box2d/box2d.h"

class PhysicalObject;
class NonPhysicalObject;

class GameObjectFactory {
public:
	virtual std::unique_ptr<PhysicalObject> createPhysicalObject(const Data& ObjectData , b2World& world) const = 0;
	virtual std::unique_ptr<NonPhysicalObject> createNonPhysicalObject(const Data& ObjectData , b2World& world) const = 0;
	virtual ~GameObjectFactory() = default;

private:
};