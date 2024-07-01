#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/DoubleHat.h"
#include "World.h"


/*
   DoubleHatFactory
   The DoubleHatFactory class is responsible for creating DoubleHat game objects.
   It provides a static method to create a DoubleHat object based on input parameters.
*/ 

class DoubleHatFactory {
public:

	static std::unique_ptr<GameObject> createObject(const std::string& line,
		World& world,
		const sf::Texture& texture);

private:

};