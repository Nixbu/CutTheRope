#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Rope.h"
#include "World.h"


class RopeFactory {
public:

	static std::unique_ptr<GameObject>&& createObject(const std::string& line,
		World& world, const sf::Texture& texture);

private:

};