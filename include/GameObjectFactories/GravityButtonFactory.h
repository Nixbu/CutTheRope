#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/GravityButton.h"
#include "World.h"

/* class GravityButtonFactory
   The GravityButtonFactory class is responsible for creating GravityButton game objects.
   It provides a static method to create a GravityButton object based on input parameters.
*/

class GravityButtonFactory {
public:

	static std::unique_ptr<GameObject> createObject(const std::string& line,
		World& world, const sf::Texture& texture);

private:

};