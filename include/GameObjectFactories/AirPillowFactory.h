#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/AirPillow.h"
#include "World.h"

/*
	class AirPillowFactory
	The AirPillowFactory class is responsible for creating AirPillow game objects.
    It provides a static method to create an AirPillow object based on input parameters.
*/

class AirPillowFactory{
public:

	static std::unique_ptr<GameObject> createObject(const std::string& line,
		World& world,
		const sf::Texture& texture);

private:
};