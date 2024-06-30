#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Rope.h"
#include "World.h"

/*
   class RopeFactory
   The RopeFactory class is responsible for creating Rope game objects.
   It provides a static method to create a Rope object based on input parameters.
*/

class RopeFactory {
public:

	static std::unique_ptr<GameObject>&& createObject(const std::string& line,
		World& world, const sf::Texture& texture);

private:

};