#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Chair.h"
#include "World.h"

/*
   ChairFactory
   The ChairFactory class is responsible for creating Chair game objects.
   It provides a static method to create a Chair object based on input parameters.
*/ 

class ChairFactory {
public:

	static std::shared_ptr<GameObject> createObject(const std::string& line, World& world, const sf::Texture& texture);

private:

};