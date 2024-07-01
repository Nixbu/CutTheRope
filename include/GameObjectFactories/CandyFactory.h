#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Candy.h"
#include "World.h"

/* 
   CandyFactory
   The CandyFactory class is responsible for creating Candy game objects.
   It provides a static method to create a Candy object based on input parameters.
*/

class CandyFactory{
public:

	static std::unique_ptr<GameObject> createObject(const std::string& line, World& world, const sf::Texture& texture);

private:

};