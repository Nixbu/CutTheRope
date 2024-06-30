#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Omnom.h"
#include "World.h"

/* class OmnomFactory
   The OmnomFactory class is responsible for creating Omnom game objects.
   It provides a static method to create an Omnom object based on input parameters.
*/

class OmnomFactory{
public:

	static std::shared_ptr<GameObject> createObject(const std::string& line, World& world, const sf::Texture& texture);

private:

};