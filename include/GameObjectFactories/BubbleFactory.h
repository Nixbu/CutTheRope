#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Bubble.h"
#include "World.h"

/*
   class BubbleFactory
   The BubbleFactory class is responsible for creating Bubble game objects.
   It provides a static method to create a Bubble object based on input parameters.
*/

class BubbleFactory {
public:

	static std::shared_ptr<GameObject> createObject(const std::string& line, 
									World& world, const sf::Texture& texture);

private:

};