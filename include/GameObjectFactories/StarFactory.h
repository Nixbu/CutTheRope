#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Star.h"
#include "World.h"

/*
   class StarFactory
   The StarFactory class is responsible for creating Star game objects.
   It provides a static method to create a Star object based on input parameters.
*/

class StarFactory{
public:

	static std::unique_ptr<GameObject>&& createObject(const std::string& line,
												World& world, 
												const sf::Texture& texture);

private:

};