#pragma once
#include <memory>
#include "Settings.h"
#include "box2d/box2d.h"

class GameObject;

class GameObjectFactory {
public:
	virtual std::unique_ptr<GameObject> && createObject(const Data& ObjectData , b2World& world) const = 0;
	virtual ~GameObjectFactory() = default;

private:
};