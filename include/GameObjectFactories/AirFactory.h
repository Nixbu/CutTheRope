#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Air.h"
#include "World.h"

/* 
   class  AirFactory
   The AirFactory class is responsible for creating Air game objects.
   It provides a static method to create an Air object based on input parameters.
*/

class AirFactory {
public:

	static std::unique_ptr<GameObject>&& createObject(const std::string& line,
								World& world, const sf::Texture& texture);

private:

};