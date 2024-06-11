#pragma once
#include <memory>
#include "GameObjects/GameObject.h"
#include "Settings.h"
#include "box2d/box2d.h"

class GameObjectFactory {
public:
	virtual std::unique_ptr<GameObject> createGameObject(const Data& ObjectData , b2World& world) const = 0;
	virtual ~GameObjectFactory() = default;
private:
};