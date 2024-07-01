#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Spikes.h"
#include "World.h"

/*
   class SpikesFactory
   The SpikesFactory class is responsible for creating Spikes game objects.
   It provides a static method to create a Spikes object based on input parameters.
*/

class SpikesFactory
{
public:

	static std::unique_ptr<GameObject> createObject(const std::string& line,
		World& world, const sf::Texture& texture);

private:

};