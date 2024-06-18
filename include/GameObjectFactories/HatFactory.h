#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Hat.h"
#include "World.h"


class HatFactory{
public:

	static std::shared_ptr<GameObject> createObject(const Data& ObjectData,
		World& world,
		const sf::Texture& texture);

private:

};